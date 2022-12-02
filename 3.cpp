#include<SDL.h>
bool jt=0;
#ifdef EMSCRIPTEN
#include<emscripten.h>
#endif
const char cl[]=
{
  0x3E, 0x0C, 0x1E, 0x1E, 0x38, 0x3F, 0x1C, 0x3F, 0x1E, 0x1E, 0x63, 0x0E, 
  0x33, 0x33, 0x2C, 0x03, 0x06, 0x30, 0x33, 0x33, 0x73, 0x0C, 0x30, 0x30, 
  0x36, 0x1F, 0x03, 0x30, 0x33, 0x33, 0x6B, 0x0C, 0x1C, 0x1C, 0x33, 0x30, 
  0x1F, 0x18, 0x1E, 0x3E, 0x67, 0x0C, 0x06, 0x30, 0x7F, 0x30, 0x33, 0x0C, 
  0x33, 0x30, 0x63, 0x0C, 0x03, 0x33, 0x30, 0x33, 0x33, 0x06, 0x33, 0x18, 
  0x3E, 0x3F, 0x3F, 0x1E, 0x30, 0x1E, 0x1E, 0x06, 0x1E, 0x0E, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const int cls=80;
struct
{
	SDL_Window* cp;
	SDL_Renderer* ck;
	SDL_Texture *mc1=NULL,*mc2=NULL;
	bool cs=1;
	int kg=0;
	const int sp1=8,sp2=8;
	int s1,s2;
	const int p1=12,p2=24;
	SDL_Rect pd;
	unsigned char *cn;
	int cns;
	SDL_RendererInfo j;
}st;
void ns(int n,int p1,int p2)
{
	for(int x1=0;x1<st.sp1;x1++)
		for(int x2=0;x2<st.sp2;x2++)
		{
			if(cl[(n/(cls/8))*cls+x2*(cls/8)+(n%(cls/8))]&(1<<x1))
			{
				int s=(p2*8+x2)*st.cns+(p1*8+x1)*3;
				st.cn[s]=255;
				st.cn[s+1]=255;
				st.cn[s+2]=255;
			}
		}
}
void lk()
{
	SDL_LockTexture(st.mc1,NULL,(void**)&st.cn,&st.cns);
	ns(1,1,1);
	ns(0,2,1);
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
	if(st.mc1)SDL_DestroyTexture(st.mc1);
	if(st.mc2)SDL_DestroyTexture(st.mc2);
	int x1,x2;
	SDL_GetWindowSize(st.cp,&x1,&x2);
	if(0)printf("%dx%d\n",x1,x2);
	st.s2=st.p2;
	float d1=((float)x2/(float)(st.s2)*(float)st.sp1/(float)st.sp2);
	st.s1=(float)x1/d1;
	st.pd.w=st.s1*d1;
	st.pd.h=x2;
	st.pd.y=0;
	st.pd.x=(x1-st.pd.w)/2;
	st.mc1=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,st.s1*st.sp1,st.s2*st.sp2);
	SDL_SetTextureScaleMode(st.mc1,SDL_ScaleModeNearest);
	int t2=ceil((float)x2/(float)(st.s2*st.sp2));
	st.mc2=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_TARGET,st.s1*st.sp1*t2,st.s2*st.sp2*t2);
	SDL_SetTextureScaleMode(st.mc2,SDL_ScaleModeLinear);
	lk();
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
void nk()
{
	SDL_Event g;
	while(SDL_PollEvent(&g))
	{
		if(g.type==SDL_QUIT)
			st.cs=0;
		if(g.type==SDL_WINDOWEVENT_RESIZED)
			mk();
		if(g.type==SDL_KEYDOWN)
			if(g.key.keysym.sym==SDLK_ESCAPE)
				st.cs=0;
	}
}
int main()
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
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
		for(int k=0;k<st.j.num_texture_formats;k++)
			printf("%d\n",st.j.texture_formats[k]);
	}
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
	return 0;
}
