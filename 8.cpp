#include<cstdio>
#include<stdint.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<functional>
typedef uint8_t kn;
typedef std::basic_string<kn> pp; 
typedef std::vector<std::pair<pp,pp>> lsp;
lsp s={
	{{1,0,3},{1}},
	{{1,5,67,0,45,6},{0}}
};
size_t mr(pp(*tk)(pp),const lsp&s)
{
	for(size_t k=0;k<s.size();k++)
		if(tk(s[k].first)!=s[k].second)
			return 0;
	return 0;
}
int main()
{
	FILE *s=fopen("vs","w");
	fseek(s,0,SEEK_END);
	auto sd=ftell(s);
	fseek(s,0,SEEK_SET);
	typedef uint32_t sp;
	sd=sd%(3*sizeof(sp))?(sd/(3*sizeof(sp))+1)*(3*sizeof(sp)):sd;
	sp* ss=(sp*)malloc(sd);
	free(ss);
	return 0;
}
