#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

void input(FILE *f) 
{
	//do something
}

void work()
{
	//do something
}

void output(FILE *f)
{
	//do something
	fprintf(f,"[");
	for (int a=1;a<=128;a++)
		fprintf(f,"{\"accusation\": [1, 2, 3],\"imprisonment\": 5,\"articles\": [5, 7, 9]}%c",a==128?']':',');
}

int main()
{
	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("result.txt","w");

	input(fin);
	work();
	output(fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
