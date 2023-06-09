#include <stdio.h>
#include <stdlib.h>
#include "taclib.h"

LABELSTACK* ls;

int cnt = 0;
void call(TAC* tac, ASTNode* arg){
        cnt++;
        //genTAC(tac,arg);
        if(getSibling(arg))
                call(tac, getSibling(arg));
        
        if(getTkNum(arg) == _INTEGER){
                emit(tac, "PushParam %d", getIVal(arg));
        }
        else if(getTkNum(arg) == _ARRAY){
                emit(tac, "PushParam %s", makePointer(getName(arg)));
        }
        else{
                emit(tac, "PushParam %s", getName(arg));
        }
}
void func(TAC* tac, ASTNode* args){
        cnt = 0;
        call(tac, getChild(args));
}
void generate(ASTNode* root, char* filename){
        int len;
        char *tacfile = 0;
        FILE *fp;
        TAC* tac = initTAC();

        for(len=0;filename[len];len++);
        tacfile = (char*)malloc(len+1);
        tacfile[len--] = '\0';
        tacfile[len--] = 't';
        for(;len>=0;len--)      tacfile[len] = filename[len];
        fp = fopen(tacfile, "w");

        checkSymbols(root);
        ls = initLabelStack();
        genTAC(tac, root);

        printTAC(tac, fp);   
        fclose(fp);
        free(tacfile);
        delLabelStack(ls);
        delTAC(tac);
        return;
}
void genTAC(TAC* tac, ASTNode* node){
        static int declaration = 0;
	static int addrForArray = 4096;
        int enterChildNode = 1, i = 0;
        ASTNode *l, *r, *m;
        char *L[20];
        if(!tac)        return;
        if(!node)       return;

       
        switch(getTkNum(node)){
        case _PROG:    
                break;
        case _VARDEC:  
                declaration = 1;
                enterChildNode = 0;
                break;
        case _FUNCDEC:  
                l = getChild(node);
                r = getSibling(getSibling(getSibling(l)));
                if (r) {
                        const char* functionName = getSVal(getSibling(l));
                        emit(tac, "%s:", functionName);
                        emit(tac, "Begin Func");
                        genTAC(tac, r);
                }
                enterChildNode = 0;
                break;
        case _ID:   
                break;
        case _ARRAY:  
                break;
        case _TYPE:
                break;
        case _PARAMS:
                declaration = 1;
                break;
        case _PARAM:
                break;
        case _CPNDSTMT: 
                l=getChild(node);
                genTAC(tac,l);
                if(r = getSibling(getChild(node))) 
                        genTAC(tac, r);
                        
                enterChildNode = 0;    
                break;
        case _LDECLIST: 
                declaration = 1;
                
                break;
        case _STMTLIST: 
                break;
        case _EXPRSTMT:
        
                break;
        case _IFSTMT:   
                {
                l=getChild(node);
                char* lb1=getLabel();
                char* lb2=getLabel();
                genTAC(tac,l);
                emit(tac,"IFZ &s Goto %s\n",getName(l),lb1);
                r=getSibling(l);
                genTAC(tac,r);
                m=getSibling(r);
                if(m){
                        emit(tac,"Goto %s\n",lb2);
                }
                emit(tac,"%s:\n",lb1);
                if(m){
                        genTAC(tac,m);
                        emit(tac,"%s:\n",lb2);
                }
                free(lb1);
                free(lb2);
                }
                //enterChildNode = 0;
                break;
     
        case _RTSTMT:   
                l = getChild(node);
                genTAC(tac,l);
                if(l){
                        if(getTkNum(l) == _INTEGER)
                                emit(tac, "Return %d", getIVal(l));
                        else
                                emit(tac, "Return %s", getName(l));
                }
                else{
                        emit(tac, "Return");
                }
                enterChildNode = 0;
                break;
        case _BRKSTMT:  
                emit(tac, "Goto %s", topLabel(ls));
                break;
        case _WHLSTMT:  
                L[0] = getLabel(), L[1] = getLabel();
                l = getChild(node), r = getSibling(l);
                emit(tac, "%s:", L[0]);
                genTAC(tac, l);
                emit(tac, "IFZ %s Goto %s", getName(l), L[1]);
                pushLabel(ls, L[1]);
                genTAC(tac, r);
                emit(tac, "Goto %s", L[0]);
                emit(tac, "%s:", L[1]);
                popLabel(ls);
                //enterChildNode = 0;
                break;
        case _DOWHLSTMT:        
                L[0] = getLabel(), L[1] = getLabel(), L[2] = getLabel();
                l = getChild(node), r = getSibling(l);
                emit(tac, "%s:", L[0]);
                pushLabel(ls, L[0]);
                pushLabel(ls, L[1]);
                pushLabel(ls, L[2]);
                genTAC(tac, l);
                emit(tac,"%s:", L[2]);
                popLabel(ls);
                genTAC(tac, r); 
                emit(tac, "IFZ %s Goto %s", getName(r), popLabel(ls));
                emit(tac, "Goto %s", popLabel(ls));
                emit(tac,"%s:", L[1]);
                //enterChildNode = 0;
                break;
        case _FORSTMT:  
                L[0] = getLabel(), L[1] = getLabel();
                l = getChild(node), m = getSibling(l), r = getSibling(m);
                //initialize
                genTAC(tac, l);
                //label for loop start
                emit(tac, "%s:", L[0]);

                //condition check
                genTAC(tac, m);
                emit(tac, "IFZ %n Goto %s", m, L[1]);

                //push the exit label to the stack
                pushLabel(ls, L[1]);

                //loop body
                genTAC(tac, getSibling(r));
                //update   
                genTAC(tac, r);
                //go back to the loop start
                emit(tac, "Goto %s", L[0]);
                //label for loop exit
                emit(tac, "%s:", popLabel(ls));
                
                break;
      
        case _INCDECEXP:     
                l = getChild(node), r = getSibling(l);
                char* name;
                if(getTkNum(r) == _ID){ 
                        if(getTkNum(r) == _ARRAY)
                                name = makePointer(getName(r));
                        else
                                name = getName(r);
                        if(getOperator(l) == INC_){
                                emit(tac, "%s = %s + 1", name, name);
                        }
                        else if(getOperator(l) == DEC_){
                                emit(tac, "%s = %s - 1", name,name);
                        }
                        setName(node, getName(r));
                }
                else if(getTkNum(l) == _ID){  
                        char* tmp1=getTmp();
                        setName(node, tmp1);
                        if(getTkNum(l) == _ARRAY)
                                name = makePointer(getName(l));
                        else
                                name = getName(l);
                        emit(tac, "%n = %s", node, name);
                        if(getOperator(r) == INC_){
                                emit(tac, "%s = %s + 1", name, name);
                        }
                        else if(getOperator(r) == DEC_){
                                emit(tac, "%s = %s - 1", name, name);
                        }
                        free(tmp1);
                }
                enterChildNode = 0;
                break;
        case _OPER:     
                break;
        case _INTEGER:  
                {
                        char str[20];
			snprintf(str, sizeof(str), "%d", getIVal(node));
			setName(node,str);
                        //enterChildNode = 0;
                }
                break;
        case _REAL:     
                break;
        case _ARGS:     
                break;
        case _FUNCCALL: 
                l = getChild(node), r = getSibling(l);

                func(tac, r);
                
                enterChildNode = 0;
                break;
        }


        if(enterChildNode){
                l = getChild(node);
                while(l){
                        genTAC(tac, l);
                        l = getSibling(l);
                }
        }

        switch(getTkNum(node)){
        case _PROG:     
                break;
        case _VARDEC:
        declaration = 0;
                break;
        case _FUNCDEC:  
                l = getChild(node);
                r= getSibling(getSibling(getSibling(l)));
                if(r){   
                        emit(tac, "End Func");
                }
                break;
        case _ID:
                break;
        case _ARRAY:    
                if(declaration){
			ASTNode* l = getChild(node);
			ASTNode* r = getSibling(l);
			emit(tac, "%n = %d", l, addrForArray);
			addrForArray += getIVal(r);
		}
		else{
                        char* tmp1=getTmp();
                        char* tmp2=getTmp();
			l = getChild(node);
			r = getSibling(l);
                        emit(tac,"%s=%n*4",tmp1,r);
                        emit(tac, "%s = %n + %s", tmp2, l, tmp1);
                        setName(node, makePointer(tmp2));
                        free(tmp1);
                        free(tmp2);
		}
                break;
        case _TYPE:
                break;
        case _PARAMS:
        declaration = 0;
                break;
        case _PARAM:
                break;
        case _CPNDSTMT: 
                break;
        case _LDECLIST: 
        declaration = 0;
                break;
        case _STMTLIST: 
                break;
        case _EXPRSTMT:
                break;
        case _IFSTMT:   
                break;
        case _SWSTMT:
                break;
        case _RTSTMT:   
                break;
        case _BRKSTMT:  
                break;
        case _WHLSTMT:  
                break;
        case _DOWHLSTMT:        
                break;
        case _FORSTMT: 
                l=getSibling(node);
                genTAC(tac,l); 
                break;
        case _INCDECEXP:        
                break;
        case _OPER:     
               {
		setName(node,getTmp());
                l = getChild(node);
                r = getSibling(l);
		int operator=getOperator(node);
                if(operator==INC_||operator==DEC_) break;
		char* op2str;
		switch (operator) {
            	case PLUS_:
                	op2str = "+";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case MINUS_:
                	op2str = "-";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case MULT_:
                	op2str = "*";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case DIV_:
                	op2str = "/";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
		case MOD_:
                	op2str = "%%";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case EQ_:
                	op2str = "==";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case NE_:
                	op2str = "!=";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case GT_:
                	op2str = ">";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
		case LT_:
                	op2str = "<";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case GE_:
                	op2str = ">=";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case LE_:
                	op2str = "<=";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
            	case AND_:
                	op2str = "&&";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
                	break;
		case OR_:
					op2str="||";
					emit(tac, "%n = %n %s %n", node, l, op2str, r);
					break;
            	case ASSIGN_:
                	emit(tac, "%s = %s", getName(l), getName(r));
                	emit(tac, "%s = %s", getName(node), getName(l));
                	break;
		case ADDASSIGN_:
                	op2str = "+";
					emit(tac, "%s = %s + %s", getName(l),getName(l),getName(r));
                	emit(tac, "%n = %s", node , getName(l));
                	break;
            	case SUBASSIGN_:
                	op2str = "-";
					emit(tac, "%s = %s %s %s", getName(l),getName(l),op2str,getName(r));
                	emit(tac, "%n = %s", node , getName(l));
                	break;
            	case MULTASSIGN_:
                	op2str = "*";
					emit(tac, "%s = %s %s %s", getName(l),getName(l),op2str,getName(r));
                	emit(tac, "%n = %s", node , getName(l));
                	break;
            	case DIVASSIGN_:
                	op2str = "/";
					emit(tac, "%s = %s %s %s", getName(l),getName(l),op2str,getName(r));
                	emit(tac, "%n = %s", node , getName(l));
                	break;
		case MODASSIGN_:
					op2str="%%";
					emit(tac, "%s = %s %s %s", getName(l),getName(l),op2str,getName(r));
                	emit(tac, "%n = %s", node , getName(l));
			break;
		default:
					op2str="";
					break;
            }
		}
                
                break;
        case _INTEGER: 
                break;
        case _REAL:    
                break;
        case _ARGS:   
                break;
        case _FUNCCALL: 
                l = getChild(node);
                setName(node, getTmp());
                emit(tac, "%n = LCall %n", node, l);
                genTAC(tac, node);
                int cntB=cnt*4;
                emit(tac, "PopParam %d", cntB);
                genTAC(tac, node);
                break;
        }
}
