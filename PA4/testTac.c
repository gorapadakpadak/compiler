// #include <stdio.h>
// #include <stdlib.h>
// #include "taclib.h"

// LABELSTACK* ls;

// int argc = 0;
// void call(TAC* tac, ASTNode* arg){
//         argc++;
//         if(getSibling(arg))
//                 call(tac, getSibling(arg));
//         genTAC(tac, arg);
//         if(getTkNum(arg) == _INTEGER)
//                 emit(tac, "PushParam %d", getIVal(arg));
//         else if(getTkNum(arg) == _ARRAY)
//                 emit(tac, "PushParam %s", makePointer(getName(arg)));
//         else
//                 emit(tac, "PushParam %n", arg);
// }
// void func(TAC* tac, ASTNode* args){
//         argc = 0;
//         call(tac, getChild(args));
// }
// void generate(ASTNode* root, char* filename){
//         int len;
//         char *tacfile = 0;
//         FILE *fp;
//         TAC* tac = initTAC();

//         for(len=0;filename[len];len++);
//         tacfile = (char*)malloc(len+1);
//         tacfile[len--] = '\0';
//         tacfile[len--] = 't';
//         for(;len>=0;len--)      tacfile[len] = filename[len];
//         fp = fopen(tacfile, "w");

//         checkSymbols(root);
//         ls = initLabelStack();
//         genTAC(tac, root);

//         printTAC(tac, fp);      // If you want to see TAC, use stdout instead of fp
//         fclose(fp);
//         free(tacfile);
//         delLabelStack(ls);
//         delTAC(tac);
//         return;
// }
// void genTAC(TAC* tac, ASTNode* node){
//         static int declaration = 0;
// 	static int addrForArray = 4096;
//         int enterChildNode = 1;
//         int i = 0;
//         ASTNode *l, *r, *m;
//         char *L[20];
//         char temp[10];
//         if(!tac)        return;
//         if(!node)       return;
//         switch(getTkNum(node)){
//         case _PROG:     
//                 break;
//         case _VARDEC:   
//                 enterChildNode = 0;
//                 break;
//         case _FUNCDEC:  
//                 l = getChild(node);
//                 r=getSibling(l);
//                 ASTNode* x= getSibling(getSibling(r));
//                 if(x){      
//                         emit(tac, "%s:", getSVal(r));
//                         emit(tac, "Begin Func");
//                         genTAC(tac, r);
//                 }
//                 enterChildNode = 0;
//                 break;
//         case _ID:       
//                 break;
//         case _ARRAY:    
//                 break;
//         case _TYPE:
//                 break;
//         case _PARAMS:
//                 break;
//         case _PARAM:
//                 break;
//         case _CPNDSTMT: 
//                 r=getSibling(getChild(node));
//                 if(r)    
//                         genTAC(tac, r);
//                 enterChildNode = 0;    
//                 break;
//         case _LDECLIST: 
//                 break;
//         case _STMTLIST: 
//                 break;
//         case _EXPRSTMT:
//                 break;
//         case _IFSTMT:   
//                 L[0] = getLabel();
//                 l = getChild(node);
//                 m = getSibling(l);
//                 r = getSibling(m);
//                 pushLabel(ls, L[0]);

//                 genTAC(tac, l);
//                 emit(tac, "IFZ %n Goto %s", l, L[0]);
//                 genTAC(tac, m);
                
//                 if(r){
//                         L[1] = getLabel();
//                         emit(tac, "Goto %s\n", L[1]);
//                 }
//                 emit(tac, "%s:\n", L[0]);
//                 if(r){
//                         pushLabel(ls, L[1]);
//                         genTAC(tac, r);
//                         emit(tac, "%s:\n", L[1]);
//                         popLabel(ls);
//                 }
//                 popLabel(ls);
//                 enterChildNode=0;
//                 break;
//         case _RTSTMT:   
//                 l = getChild(node);
//                 if(l){
//                         if(getTkNum(l) == _INTEGER){
//                                 int k=getIVal(l);
//                                 emit(tac, "Return %d", k);
//                         }
//                         else
//                                 emit(tac, "Return %n", l);
//                 }
//                 else{
//                         emit(tac, "Return");
//                 }
//                 enterChildNode = 0;
//                 break;
//         case _BRKSTMT:  
//                 emit(tac, "Goto %s\n", topLabel(ls));
//                 break;
//         case _WHLSTMT: 
//                 l = getChild(node);
//                 r = getSibling(l); 
//                 L[0] = getLabel();
//                 L[1] = getLabel();
//                 emit(tac, "%s:\n", L[0]);
//                 pushLabel(ls, L[1]);

//                 genTAC(tac, l);
//                 emit(tac, "IFZ %n Goto %s", l, L[1]);

//                 genTAC(tac, r);
//                 emit(tac, "Goto %s", L[0]);
//                 emit(tac, "%s:\n", popLabel(ls));
//                 enterChildNode = 0;
//                 break;
//         case _DOWHLSTMT:  
//                 l = getChild(node);
//                 r = getSibling(l);     
//                 L[0] = getLabel();
//                 L[1] = getLabel();
//                 L[2] = getLabel();

//                 emit(tac, "%s:\n", L[0]);
//                 pushLabel(ls, L[0]);
//                 pushLabel(ls, L[1]);
//                 pushLabel(ls, L[2]);
//                 genTAC(tac, l);
                
//                 emit(tac,"%s:\n", L[2]);
//                 popLabel(ls);
//                 genTAC(tac, r); 
//                 emit(tac, "IFZ %n Goto %s", r, popLabel(ls));
//                 emit(tac, "Goto %s\n", popLabel(ls));
//                 emit(tac,"%s:\n", L[1]);
        
//                 enterChildNode = 0;
//                 break;
//         case _FORSTMT:  
//                 L[0] = getLabel();
//                 L[1] = getLabel();
//                 l = getChild(node);
//                 m = getSibling(l);
//                 r = getSibling(m);
//                 genTAC(tac, l);
//                 emit(tac, "%s:", L[0]);

//                 genTAC(tac, m);
//                 emit(tac, "IFZ %n Goto %s", m, L[1]);
//                 pushLabel(ls, L[1]);

//                 genTAC(tac, getSibling(r));     
//                 genTAC(tac, r);
//                 emit(tac, "Goto %s\n", L[0]);
//                 emit(tac, "%s:\n", popLabel(ls));
//                 enterChildNode=0;
//                 break;
//         case _INCDECEXP:        
//                 l = getChild(node);
//                 r = getSibling(l);
                
//                 if(getTkNum(l) == _ID){  
//                         setName(node, getTmp());
//                         if(getTkNum(l) == _ARRAY)
//                                 L[0] = makePointer(getName(l));
//                         else
//                                 L[0] = getName(l);
//                         emit(tac, "%n = %s", node, L[0]);
//                         if(getOperator(r) == INC_){
//                                 emit(tac, "%s = %s + 1", L[0], L[0]);
//                         }
//                         else if(getOperator(r) == DEC_){
//                                 emit(tac, "%s = %s - 1", L[0], L[0]);
//                         }
//                 }
//                 else if(getTkNum(r) == _ID){  

//                         if(getTkNum(r) == _ARRAY)
//                                 L[0] = makePointer(getName(r));
//                         else
//                                 L[0] = getName(r);
//                         if(getOperator(l) == INC_){
//                                 emit(tac, "%s = %s + 1",L[0], L[0]);
//                         }
//                         else if(getOperator(l) == DEC_){
//                                 emit(tac, "%s = %s - 1", L[0], L[0]);
//                         }
//                         setName(node, getName(r));
//                 }
//                 enterChildNode = 0;
//                 break;
//         case _OPER:     
//                 break;
//         case _INTEGER:  
//                 {
// 			snprintf(temp, sizeof(temp), "%d", getIVal(node));
// 			setName(node,temp);
// 		}
//                 break;
//         case _REAL:     
//                 break;
//         case _ARGS:     
//                 break;
//         case _FUNCCALL: 
//                 l = getChild(node);
//                 r = getSibling(l);
//                 func(tac, r);
//                 enterChildNode=0;
//                 break;
//         }

//         if(enterChildNode){
//                 l = getChild(node);
//                 while(l){
//                         genTAC(tac, l);
//                         l = getSibling(l);
//                 }
//         }

//         switch(getTkNum(node)){
//         case _PROG:    
//                 break;
//         case _VARDEC:
//                 break;
//         case _FUNCDEC:  
//                 l = getChild(node);
//                 r = getSibling(getSibling(getSibling(l)));
//                 if(r){     
//                         emit(tac, "End Func");
//                 }
//                 break;
//         case _ID:
//                 break;
//         case _ARRAY:   
//                 if(declaration){
// 			ASTNode* l = getChild(node);
// 			ASTNode* r = getSibling(l);
// 			emit(tac, "%n = %d", l, addrForArray);
// 			addrForArray += getIVal(r);
// 		}else{
//                 l = getChild(node);
//                 r = getSibling(l);
//                 m = makeASTNodeTYPE(NO_TYPE);
//                 setName(m, getTmp());
//                 emit(tac, "%n = %n * 4", m, r);
//                 setName(node, getTmp());
//                 emit(tac, "%n = %n + %n", node, l, m);
//                 }
               
//                 break;
//         case _TYPE:
//                 break;
//         case _PARAMS:
//                 break;
//         case _PARAM:
//                 break;
//         case _CPNDSTMT: 
//                 break;
//         case _LDECLIST: 
//                 break;
//         case _STMTLIST: 
//                 break;
//         case _EXPRSTMT:
//                 break;
//         case _IFSTMT:   
//                 break;
//         case _SWSTMT:
//                 break;
//         case _RTSTMT:   
//                 break;
//         case _BRKSTMT:  
//                 break;
//         case _WHLSTMT:  
//                 break;
//         case _DOWHLSTMT:       
//                 break;
//         case _FORSTMT:  
//                 break;
//         case _CASE:
//                 break;
//         case _DEFAULT:
//                 break;
//         case _INCDECEXP:        
//                 break;
//         case _OPER:     
        //         {
	// 	setName(node,getTmp());
        //         ASTNode* left = getChild(node);
        //         ASTNode* right = getSibling(left);

	// 	if(getTkNum(left)==_ARRAY){
	// 		L[0]=makePointer(getName(left));
	// 	}
	// 	else{
	// 		L[0]=getName(left);
	// 	}

	// 	if(getTkNum(right)==_ARRAY){
	// 		L[1]=makePointer(getName(right));
	// 	}
	// 	else{
	// 		L[1]=getName(right);
	// 	}

	// 	int operator=getOperator(node);
	// 	char* op2str;
	// 	switch (operator) {
        //     	case PLUS_:
        //         	op2str = "+";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case MINUS_:
        //         	op2str = "-";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case MULT_:
        //         	op2str = "*";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case DIV_:
        //         	op2str = "/";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
	// 	case MOD_:
        //         	op2str = "%%";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case EQ_:
        //         	op2str = "==";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case NE_:
        //         	op2str = "!=";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case GT_:
        //         	op2str = ">";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
	// 	case LT_:
        //         	op2str = "<";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case GE_:
        //         	op2str = ">=";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case LE_:
        //         	op2str = "<=";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
        //     	case AND_:
        //         	op2str = "&&";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
        //         	break;
	// 	case OR_:
	// 				op2str="||";
	// 				emit(tac, "%n = %s %s %s", node, L[0], op2str, L[1]);
	// 				break;
        //     	case ASSIGN_:
        //         	emit(tac, "%s = %s", getName(left), getName(right));
        //         	emit(tac, "%s = %s", getName(node), getName(left));
        //         	break;
	// 	case ADDASSIGN_:
        //         	op2str = "+";
	// 				emit(tac, "%s = %s + %s", getName(left),getName(left),getName(right));
        //         	emit(tac, "%n = %s", node , getName(left));
        //         	break;
        //     	case SUBASSIGN_:
        //         	op2str = "-";
	// 				emit(tac, "%s = %s %s %s", getName(left),getName(left),op2str,getName(right));
        //         	emit(tac, "%n = %s", node , getName(left));
        //         	break;
        //     	case MULTASSIGN_:
        //         	op2str = "*";
	// 				emit(tac, "%s = %s %s %s", getName(left),getName(left),op2str,getName(right));
        //         	emit(tac, "%n = %s", node , getName(left));
        //         	break;
        //     	case DIVASSIGN_:
        //         	op2str = "/";
	// 				emit(tac, "%s = %s %s %s", getName(left),getName(left),op2str,getName(right));
        //         	emit(tac, "%n = %s", node , getName(left));
        //         	break;
	// 	case MODASSIGN_:
	// 				op2str="%%";
	// 				emit(tac, "%s = %s %s %s", getName(left),getName(left),op2str,getName(right));
        //         	emit(tac, "%n = %s", node , getName(left));
	// 		break;
	// 	default:
	// 				op2str="";
	// 				break;
        //     }
	// 	}
                
//                 break;
//         case _INTEGER:  
//                 break;
//         case _REAL:  
//                 break;
//         case _ARGS:   
//                 break;
//         case _FUNCCALL:
//                 l = getChild(node);
//                 setName(node, getTmp());
//                 emit(tac, "%n = LCall %n", node, l);
//                 emit(tac, "PopParam %d", argc * 4);
//                 break;
//         }
// }