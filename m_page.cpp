#include"all.h"
#include"stru.h"
#include"public.h"
void m_page()
{
	int *choice;//0 for search,1 for choose 
	first_page();
	m_choose(choice);
	main_page(choice);
}