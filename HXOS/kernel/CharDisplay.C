//***********************************************************************/
//    Author                    : tywind
//    Original Date             : Nov,02 2014
//    Module Name               : CharDisplay
//    Module Funciton           : 
//                                
//                                
//
//    Last modified Author      :
//    Last modified Date        :
//    Last modified Content     :
//                                1.
//                                2.
//    Lines number              :
//***********************************************************************/

#ifndef __STDAFX_H__
#include "..\INCLUDE\STDAFX.H"
#endif

#ifndef __KAPI_H__
#include "..\INCLUDE\KAPI.H"
#endif
#include "..\include\console.h"
#include "..\INCLUDE\CharDisPlay.H"



//##################老版本字符显示接口实现,已经全部定向到新接口实现####################

void PrintStr(const char* pszMsg)
{
	CD_PrintString((LPSTR)pszMsg,FALSE);
}

void ClearScreen()
{
	CD_Clear();
}

void PrintCh(unsigned short ch)
{
	CD_PrintChar((CHAR)ch);
}
void GotoHome()
{
	CD_GotoHome();
}
void ChangeLine()
{
	CD_ChangeLine();
}

VOID GotoPrev()
{
	CD_GotoPrev();
}

//###############新版字符显示接口实现######################
//初始化显示设备
VOID CD_InitDisplay(INT nDisplayMode)
{	
	return ;
}

//设置显示模式
VOID CD_SetDisplayMode(INT nMode)
{
	return ;
}

//得到行和列
VOID CD_GetDisPlayRang(WORD* pLines,WORD* pColums)
{
#ifdef __I386__
	VGA_GetDisplayRange(pLines,pColums);
#endif	
}

//得到当前光标位置
VOID  CD_GetCursorPos(WORD* pCursorX,WORD* pCursorY)
{
#ifdef __I386__
	VGA_GetCursorPos(pCursorX,pCursorY);
#endif 
}

//换行
VOID CD_GotoHome()
{

#ifdef __I386__
	WORD CursorX = 0;
	WORD CursorY = 0;

	CD_GetCursorPos(&CursorX,&CursorY);
	CD_SetCursorPos(0,CursorY);
#endif 

#ifdef __CFG_SYS_CONSOLE
	Console.GotoHome();
#endif
}

//回到上一个字符
VOID CD_GotoPrev()
{
#ifdef __I386__

	WORD CursorX = 0;
	WORD CursorY = 0;

	CD_GetCursorPos(&CursorX,&CursorY);
	if(CursorX > 0 )
		{
		CD_SetCursorPos(CursorX-1,CursorY);
		}

#endif

#ifdef __CFG_SYS_CONSOLE
	Console.GotoPrev();
#endif
}
//换行
VOID CD_ChangeLine()
{
#ifdef __I386__
	VGA_ChangeLine();
#endif

#ifdef __CFG_SYS_CONSOLE
	Console.GotoHome();
	Console.ChangeLine();
#endif

}
//设置当前光标位置
VOID  CD_SetCursorPos(WORD nCursorX,WORD nCursorY)
{
	#ifdef __I386__
		VGA_SetCursorPos(nCursorX,nCursorY);
	#endif
}

//打印字符串,cl表示是否换行
VOID CD_PrintString(LPSTR pStr,BOOL cl)
{
#ifdef __I386__
	VGA_PrintString(pStr,cl);
#endif

	#ifdef __CFG_SYS_CONSOLE
	Console.PrintStr(pStr);
	
		if(cl == TRUE)
			{
	    CD_ChangeLine();	
			}
	#endif	
}

//打印一个字符
VOID CD_PrintChar(CHAR ch)
{

#ifdef __I386__
		VGA_PrintChar(ch);
#endif

#ifdef __CFG_SYS_CONSOLE
		Console.PrintCh(ch);
#endif
}

//从指定位置得到字符串
VOID  CD_GetString(WORD nCursorX,WORD nCursorY,LPSTR pString,INT nBufLen)
{
#ifdef __I386__
	VGA_GetString(nCursorX,nCursorY,pString,nBufLen);	
#endif
}

//删除字符串
VOID  CD_DelString(WORD nCursorX,WORD nCursorY,INT nDelLen)
{
#ifdef __I386__
	VGA_DelString(nCursorX,nCursorY,nDelLen);
#endif
}

//删除字符
VOID  CD_DelChar(INT nDelMode)
{
#ifdef __I386__
	VGA_DelChar(nDelMode);
#endif
}

//清屏
VOID  CD_Clear()
{
#ifdef __I386__
	VGA_Clear();
#endif

#ifdef __CFG_SYS_CONSOLE
	Console.ClearScreen();
#endif
}
