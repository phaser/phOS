void _main()
{
	extern void (*__CTOR_LIST__)();
	void (**constructor)() = &__CTOR_LIST__;
	int total = *(int *)constructor;

	constructor++;

	while (total)
	{
		(*constructor)();
		total--;
		constructor++;
	}
}

void _atexit()
{
	extern void (*__DTOR_LIST__)();
	void (**deconstructor)() = &__DTOR_LIST__;
	int total = *(int *)deconstructor;
	deconstructor++;

	while (total)
	{
		(*deconstructor)();
		total--;
		deconstructor++;
	}
}

int __cxa_atexit ( void (*f)(void *), void *p, void *d )
{
	(*f)((void*)0);
}
