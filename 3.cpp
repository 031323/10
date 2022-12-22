#include<SDL.h>
bool jt=0;
#ifdef EMSCRIPTEN
#include<emscripten.h>
#endif
#include"nc.xbm"
#include<limits.h>
const int cls=nc_width;
typedef uint32_t sp;
const size_t pd=1000;
sp ps[10][pd]=
{
	{0,
		0,0,4,0,1000},
};
struct
{
	SDL_Window* cp;
	SDL_Renderer* ck;
	SDL_Texture *mc1=NULL,*mc2=NULL;
	bool cs=1;
	int kg=0;
	const int sp1=8,sp2=(nc_height>128)?16:8;
	int s1,s2,l2=1,ps=1;
	const int p1=15,p2=sp2==8?32:24;
	SDL_Rect pd;
	unsigned char *cn;
	int cns;
	SDL_RendererInfo j;
	bool tp=0;
	size_t pk=0;
	size_t ls=1;
	size_t ds=0;
	const size_t sk=100000;
	sp* s;
	bool plg=1;
	bool ks=([](){char *d=getenv("KS");return !(!d||d[0]=='0');})();
	char tks[100]="0";
	struct
	{
		double k=0;
		int s=0;
		int n=0;
		int p=0;
	}tr;
	int lsk=5;
	unsigned long int g=1;
}st;
sp& sts(size_t k)
{
	return k==st.sk?st.s[0]:st.s[k];
}
struct nl
{
	int n=0;
	float p1=0,p2=0;
	bool v=0;
	unsigned char rm=255,hm=255,nm=255;
	void operator()()
	{
		int s1=round(p1*st.sp1);
		int s2=round(p2*st.sp2);
		for(int x2=0;x2<st.sp2;x2++)
		{
			unsigned char c=nc_bits[(n/(cls/st.sp1))*(cls/st.sp1)*st.sp2+x2*(cls/st.sp1)+(n%(cls/st.sp1))];
			if(nc_bits[0]==255)c=255-c;
			if(v)c=255-c;
			for(int x1=0;x1<st.sp1;x1++)
			{
				if(c&(1<<x1))
				{
					int s=(s2+x2)*st.cns+(s1+x1)*3;
					st.cn[s]=st.ks?255-rm:rm;
					st.cn[s+1]=st.ks?255-hm:hm;
					st.cn[s+2]=st.ks?255-nm:nm;
				}
			}
		}
	}
};
void ns(int n,float p1,float p2,bool v=0)
{
	nl({.n=n,.p1=p1,.p2=p2,.v=v})();
}
void cnk(int k,int m1,int m2,float p1,float p2)
{
	for(int x1=0;x1<m1;x1++)
		for(int x2=0;x2<m2;x2++)
		{
			ns(k+x2*(cls/st.sp1)+x1,p1+x1,p2+x2);
		}
}
void pss(size_t pk)
{
	st.pk=pk;
	memset(st.s,0,sizeof(sp)*st.sk);
	for(size_t k=0;k<pd&&k<(size_t)st.sk;k++)
		st.s[k]=ps[pk-1][k];
}
void lk()
{
	SDL_LockTexture(st.mc1,NULL,(void**)&st.cn,&st.cns);
	memset(st.cn,st.ks?255:0,st.s2*st.cns*8);
	const int ks=5,lsk=st.lsk;
	for(int k=0;st.tks[k]!=0;k++)ns(st.tks[k]-'0',1+k,1,1);
	if(0)for(int k=0,b=10;k<ks;k++,b*=10)ns((st.pk%b)*10/b,ks-k,1,1);
	size_t pn=st.ls;
	for(int k=0;(k<lsk&&pn>0)||k==0;k++,pn/=10)ns(pn%10,st.s1-2-k,1);
	if(0)cnk(23,1,2,st.s1-lsk-2,1);
	for(int k=1;k<st.s1-1;k++)ns(10,k,2);
	int l1=st.s1-2,l2=st.s2-4;
	int p1=1,p2=3;
	if(st.tp)
	{
		for(int i=0;i<10;i++)ns(i,1+(i%5)*3,st.s2-4+(int)(i/5)*2);
		for(int i=11;i<16;i++)ns(i,1+(i-11)*3,st.s2-6);
		for(int k=1;k<st.s1-1;k++)ns(10,k,st.s2-7);
		l2-=6;
	}
	st.l2=l2;
	int ps=l1/(lsk+1);
	st.ps=ps;
	if(st.ds%st.l2)st.ds=(st.ds/st.l2)*st.l2;
	while(st.ls-st.ds>(size_t)ps*l2)st.ds+=st.l2;
	for(int sk=0;sk<ps*l2;sk++)
	{
		if(st.ds+sk>=st.sk)
			break;
		sp pn=sts(1+st.ds+sk);
		for(int k=0;(k<lsk&&pn>0)||k==0;k++,pn/=10)
			ns(pn%10,p1-2+(lsk+1)*(1+(int)(sk/l2))-k,p2+(sk%l2),0);
	}
	if(1)nl({.n=st.tks[0]=='0'?16:st.tks[0]=='1'?26:24,.p1=(float)(p1-1+(lsk+1)*(1+(int)((st.ls-1-st.ds)/l2))),.p2=(float)(p2+((st.ls-1-st.ds)%l2)),
			.rm=255,.hm=255,.nm=255})();
	SDL_UnlockTexture(st.mc1);
	SDL_SetRenderTarget(st.ck,st.mc2);
	SDL_RenderCopy(st.ck,st.mc1,NULL,NULL);
	SDL_SetRenderTarget(st.ck,NULL);
    SDL_SetRenderDrawColor(st.ck,0,0,0,255);
	SDL_RenderClear(st.ck);
    SDL_RenderCopy(st.ck,st.mc2,NULL,&st.pd);
	SDL_RenderPresent(st.ck);
}
void mk()
{
	st.tr.p=0;
	if(st.mc1)SDL_DestroyTexture(st.mc1);
	if(st.mc2)SDL_DestroyTexture(st.mc2);
	int x1,x2;
	SDL_GetWindowSize(st.cp,&x1,&x2);
	if(0)printf("%dx%d\n",x1,x2);
	if(x1>x2)
	{
		st.tp=0;
		st.s2=st.p2;
		float d1=((float)x2/(float)(st.s2)*(float)st.sp1/(float)st.sp2);
		st.s1=ceil((float)x1/d1);
		SDL_ShowCursor(SDL_DISABLE);
	}
	else
	{
		st.tp=1;
		st.s1=st.p1;
		float d2=((float)x1/(float)(st.s1)*(float)st.sp2/(float)st.sp1);
		st.s2=floor((float)x2/d2);
		SDL_ShowCursor(SDL_ENABLE);
	}
	st.pd.w=x1;
	st.pd.h=st.s2*((float)x1/(float)(st.s1)*(float)st.sp2/(float)st.sp1);
	st.pd.y=0;
	st.pd.x=0;
	int t2=ceil((float)x1/(float)(st.s1*st.sp1));
	st.mc1=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,st.s1*st.sp1,st.s2*st.sp2);
	if(!getenv("NCTV"))SDL_SetTextureScaleMode(st.mc1,SDL_ScaleModeNearest);
	st.mc2=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_TARGET,st.s1*st.sp1*t2,st.s2*st.sp2*t2);
	if(!getenv("NCTV"))SDL_SetTextureScaleMode(st.mc2,SDL_ScaleModeLinear);
	st.plg=1;
}
#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE pp(int x1,int x2)
{
	SDL_SetWindowSize(st.cp,x1,x2);
	mk();
}
}
#endif
void ydk()
{
	sts(1)=0;
	sts(2)=6;
}
bool yk()
{
	if(sts(2)>=sts(3))
	{
		ydk();
		return 0;
	}
	else
	{
		sts(2)++;
		return 1;
	}
}
void dsk(int d)
{
	auto cs=[](){return st.ls>sts(4)&&st.ls<sts(5);};
	if(d==4)
	{
		st.ls++;
		if(st.ls>st.sk)st.ls--;
		if(st.ls-st.ds>(size_t)(st.ps*st.l2))st.ds+=st.l2;
		if(!cs())st.tks[0]='0';
	}
	else if(d==2)
	{
		st.ls+=st.l2;
		if(st.ls>st.sk)st.ls=st.sk;
		if(st.ls-st.ds>(size_t)(st.ps*st.l2))st.ds+=st.l2;
	}
	else if(d==3)
	{
		if(st.ls>1)st.ls--;
		if(st.ds>=st.ls)st.ds-=st.l2;
		if(!cs())st.tks[0]='0';
	}
	else if(d==1)
	{
		if(st.ls>(size_t)st.l2)st.ls-=st.l2;
		else {st.ls=1;st.ds=0;}
		if(st.ds>=st.ls)st.ds-=st.l2;
		if(st.ds<0)st.ds=0;
	}
	else if(d>4&&d<15)
	{
		int p=d-5;
		if(p==1&&cs())
		{
			st.tks[0]='1';
			st.tr.p=0;
		}
		else if(p==2)
		{
			st.tks[0]='2';
			st.tr.p=0;
			st.g=1;
		}
	}
}
void spk(int d)
{
	if(d==3)dsk(3);
	else if(d==4)dsk(4);
	else if(d==1)
	{
		sts(st.ls)/=10;
	}
	else if(d==2)
	{
		st.tks[0]='0';
		st.tr.p=0;
	}
	else if(d>4&&d<15)
	{
		int p=d-5;
		sp s=sts(st.ls);
		static size_t dg[]={1,10,100,1000,10000,100000};
		size_t nn=s*10+p;
		if(nn<dg[st.lsk]&&(nn<=st.sk))
			sts(st.ls)=nn;
		st.tr.p=0;
	}
}
void nk()
{
	static double k;
	SDL_Event g;
	const int tpss=25;
	static char tps[tpss];
	auto tpm=[](){memset(tps,0,tpss);};
	while(SDL_PollEvent(&g))
	{
		auto ss=[](int s1,int s2)->int
		{
			int k1=(double)(s1-st.pd.x)/(double)st.pd.w*(double)st.s1;
			int k2=round((double)(s2-st.pd.y)/(double)st.pd.h*(double)st.s2)-st.s2+6;
			printf("%d %d \n",k1,k2);
			return k2<0?-1:(k2/2)*5+k1/3;
		};
		auto ts=[&g]()
		{
			int n=0;
			if(g.key.keysym.sym==SDLK_DOWN)
				n=4;
			else if(g.key.keysym.sym==SDLK_RIGHT)
				n=2;
			else if(g.key.keysym.sym==SDLK_UP)
				n=3;
			else if(g.key.keysym.sym==SDLK_LEFT)
				n=1;
			else if(g.key.keysym.sym==SDLK_BACKSPACE&&st.tks[0]=='1')
				n=1;
			else if(g.key.keysym.sym==SDLK_0)
				n=5;
			else if(g.key.keysym.sym==SDLK_1)
				n=6;
			else if(g.key.keysym.sym==SDLK_2)
				n=7;
			else if(g.key.keysym.sym==SDLK_3)
				n=8;
			else if(g.key.keysym.sym==SDLK_4)
				n=9;
			else if(g.key.keysym.sym==SDLK_5)
				n=10;
			else if(g.key.keysym.sym==SDLK_6)
				n=11;
			else if(g.key.keysym.sym==SDLK_7)
				n=12;
			else if(g.key.keysym.sym==SDLK_8)
				n=13;
			else if(g.key.keysym.sym==SDLK_9)
				n=14;
			else if(g.key.keysym.sym==SDLK_KP_0)
				n=15;
			else if(g.key.keysym.sym==SDLK_KP_1)
				n=16;
			else if(g.key.keysym.sym==SDLK_KP_2)
				n=17;
			else if(g.key.keysym.sym==SDLK_KP_3)
				n=18;
			else if(g.key.keysym.sym==SDLK_KP_4)
				n=19;
			else if(g.key.keysym.sym==SDLK_KP_5)
				n=20;
			else if(g.key.keysym.sym==SDLK_KP_6)
				n=21;
			else if(g.key.keysym.sym==SDLK_KP_7)
				n=22;
			else if(g.key.keysym.sym==SDLK_KP_8)
				n=23;
			else if(g.key.keysym.sym==SDLK_KP_9)
				n=24;
			return n;
		};
		if(g.type==SDL_QUIT)
			st.cs=0;
		else if(g.type==SDL_WINDOWEVENT_RESIZED)
			mk();
		else if(g.type==SDL_WINDOWEVENT_FOCUS_LOST)
		{
			tpm();
			st.tr.p=0;
		}
		else if(g.type==SDL_KEYUP)
		{
			if((st.tr.p==1)&&ts()==st.tr.n)st.tr.p=0;
			tps[ts()]=0;
		}
		else if(g.type==SDL_KEYDOWN)
		{
			if(g.key.keysym.sym==SDLK_ESCAPE)
			{
				st.cs=0;
				st.tr.p=0;
			}
			int n=ts();
			if(tps[n]==0)
			{
				tps[n]=1;
				if(n>14)n-=10;
				if(n>0&&n<15)
				{
					st.tr.p=1;
					st.tr.n=n;
					st.tr.k=0;
					st.tr.s=0;
				}
			}
		}
		if(g.type==SDL_MOUSEBUTTONUP)
			if(st.tr.p==2)st.tr.p=0;
		if(g.type==SDL_MOUSEBUTTONDOWN)
			if(st.tr.p==0)
			{
				int n=ss(g.button.x,g.button.y);
				if(n>0&&n<15)
				{
					st.tr.p=2;
					st.tr.n=n;
					st.tr.k=0;
					st.tr.s=0;
				}
			}
		if(g.type==SDL_MOUSEMOTION)
			if(st.tr.p==2&&ss(g.button.x,g.button.y)!=st.tr.n)
				st.tr.p=0;
	}
	double sk=(double)SDL_GetTicks()/1000.0;
	if(st.tks[0]=='2')
	{
		st.plg=1;
		for(unsigned long k=0;k<st.g;k++)
			if(!yk())
			{
				st.tr.p=0;
				st.tks[0]='0';
				break;	
			}
		double pk=(double)SDL_GetTicks()/1000.0;
		if(pk-sk<0.006)st.g*=2;
		else if(st.g>1)st.g/=2;
	}
	st.tr.k+=sk-k;
	k=sk;
	if(st.tr.p==1||st.tr.p==2)
	{
		const double dk=.25;
		st.plg=1;
		if(st.tr.s==0||(st.tr.k-dk)/0.05>st.tr.s-1)
		{
			st.tr.s++;
			if(st.tks[0]=='0')dsk(st.tr.n);
			else if(st.tks[0]=='1')
			{
				spk(st.tr.n);
			}
			else if(st.tks[0]=='2'&&st.tr.n==5+3)
				sts(2)=sts(3);
		}
	}
	if(st.plg){st.plg=0;lk();}
}
int main()
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
	SDL_ShowCursor(SDL_DISABLE);
#ifdef EMSCRIPTEN
	jt=1;
	st.cp=SDL_CreateWindow(0,0,0,
			EM_ASM_INT({return window.visualViewport.width;}),
			EM_ASM_INT({return window.visualViewport.height;}),
			SDL_WINDOW_RESIZABLE);
#else
	st.cp=SDL_CreateWindow(0,0,0,0,0,SDL_WINDOW_FULLSCREEN_DESKTOP);
#endif
	st.ck=SDL_CreateRenderer(st.cp,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);
	if(0)
	{
		SDL_GetRenderDriverInfo(0,&st.j);
		for(unsigned int k=0;k<st.j.num_texture_formats;k++)
			printf("%d\n",st.j.texture_formats[k]);
	}
	st.s=new sp[st.sk];
	srand(100);
	pss(1);
	ydk();
	mk();
#ifndef EMSCRIPTEN
	while(st.cs)
	{
		nk();
		SDL_Delay(16);
	}
#else
	emscripten_set_main_loop(nk,0,1);
#endif
	SDL_DestroyRenderer(st.ck);
	SDL_DestroyWindow(st.cp);
	SDL_DestroyTexture(st.mc1);
	SDL_DestroyTexture(st.mc2);
	SDL_Quit();
	delete st.s;
	return 0;
}
