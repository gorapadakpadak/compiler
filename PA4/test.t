main:
	Begin Func
	i = 0
	_t0 = i
L0:
	IFZ _t1 Goto L1
	_t2=i*4
	_t3 = a + _t2
	*(_t3) = _t4
	_t5 = *(_t3)
	_t6 = i
	i = i + 1
	Goto L0
L1:
	i = 0
	_t7 = i
	_t9 = i
	i = i + 1
	_t10=i*4
	_t11 = a + _t10
	*(_t11) = _t12
	_t13 = *(_t11)
	End Func
isPrime:
	Begin Func
	i = 2
	_t14 = i
	End Func
