#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

bool g = 0;

string dad(string a) { 
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "bro_old") return "dad_bro_old";//伯父
    if (a == "bro_young") return "dad_bro_young";//叔父
    if (a == "sis_old") return "dad_sis_old";//姑媽
    if (a == "sis_young") return "dad_sis_young";//姑媽
    if (a == "wife") return "mom";//母親
    if (a == "daughter" && g == 0) return "sis_old";//自己(預設) 先改成姐姐
    if (a == "daughter" && g == 1) return "me_female";//自己(預設) 
    if (a == "daughter_old") return "sis_old";//姊姊
    if (a == "daughter_young") return "sis_young";//妹妹
    if (a == "son" && g == 0) return "bro_old";//自己(預設)
    if (a == "son" && g == 1) return "bro_old";//自己(預設) 先改成哥哥
    if (a == "son_old") return "bro_old";//哥哥
    if (a == "son_young") return "bro_young";//弟弟
}

string mom(string a) { 
    if (a == "dad") return "mom_dad";//外祖父
    if (a == "mom") return "mom_mom";//外祖母
    if (a == "bro_old") return "mom_bro_old";//舅舅
    if (a == "bro_young") return "mom_bro_old";//舅舅
    if (a == "sis_old") return "mom_sis_old";//姨媽
    if (a == "sis_young") return "mom_sis_young";//姨媽
    if (a == "husband") return "dad";//父親
    if (a == "daughter" && g == 0) return "sis_old";//自己(預設) 先改成姐姐
    if (a == "daughter" && g == 1) return "me_female";//自己(預設) 
    if (a == "daughter_old") return "sis_old";//姊姊
    if (a == "daughter_young") return "sis_young";//妹妹
    if (a == "son" && g == 0) return "bro_old";//自己(預設)
    if (a == "son" && g == 1) return "bro_old";//自己(預設) 先改成哥哥
    if (a == "son_old") return "bro_old";//哥哥
    if (a == "son_young") return "bro_young";//弟弟
}

string bro_old(string a) { 
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "bro_old";//
    if (a == "bro_young") return "me";//
    if (a == "sis_old") return "sis_old";//
    if (a == "sis_young") return "sis_young";//
    if (a == "wife") return "bro_old_wife";//嫂嫂
    if (a == "daughter") return "bro_old_daughter";//姪女
    if (a == "daughter_old") return "bro_old_daughter";//姪女
    if (a == "daughter_young") return "bro_old_daughter";//姪女
    if (a == "son") return "bro_old_son";//姪子
    if (a == "son_old") return "bro_old_son";//姪子
    if (a == "son_young") return "bro_old_son";//姪子
}

string bro_young(string a) {
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "me";//
    if (a == "bro_young") return "bro_young";//
    if (a == "sis_old") return "sis_old";//
    if (a == "sis_young") return "sis_young";//
    if (a == "wife") return "bro_young_wife";//弟媳
    if (a == "daughter") return "bro_young_daughter";//姪女
    if (a == "daughter_old") return "bro_young_daughter";//姪女
    if (a == "daughter_young") return "bro_young_daughter";//姪女
    if (a == "son") return "bro_young_son";//姪子
    if (a == "son_old") return "bro_young_son";//姪子
    if (a == "son_young") return "bro_young_son";//姪子
}

string sis_old(string a) {
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "bro_old";//
    if (a == "bro_young") return "me";//
    if (a == "sis_old") return "sis_old";//
    if (a == "sis_young") return "me";//
    if (a == "husband") return "sis_old_husband";//姊夫
    if (a == "daughter") return "sis_old_daughter";//外甥女
    if (a == "daughter_old") return "sis_old_daughter";//外甥女
    if (a == "daughter_young") return "sis_old_daughter";//外甥女
    if (a == "son") return "sis_old_son";//外甥
    if (a == "son_old") return "sis_old_son";//外甥
    if (a == "son_young") return "sis_old_son";//外甥
}

string sis_young(string a) {
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "me";//
    if (a == "bro_young") return "me";//
    if (a == "sis_old") return "me";//
    if (a == "sis_young") return "sis_young";//
    if (a == "husband") return "sis_young_husband";//妹夫
    if (a == "daughter") return "sis_young_daughter";//外甥女
    if (a == "daughter_old") return "sis_young_daughter";//外甥女
    if (a == "daughter_young") return "sis_young_daughter";//外甥女
    if (a == "son") return "sis_young_son";//外甥
    if (a == "son_old") return "sis_young_son";//外甥
    if (a == "son_young") return "sis_young_son";//外甥
}

string husband(string a) {
    if (a == "dad") return "husband_dad";//夫父
    if (a == "mom") return "husband_mom";//夫母
    if (a == "bro_old") return "husband_bro_old";//夫兄
    if (a == "bro_young") return "husband_bro_young";//夫弟
    if (a == "sis_old") return "husband_sis_old";//夫姊
    if (a == "sis_young") return "husband_sis_young";//夫妹
    if (a == "wife") return "me_female";//我(女)
    if (a == "daughter") return "daughter";//女兒
    if (a == "daughter_old") return "daughter";//女兒
    if (a == "daughter_young") return "daughter";//女兒
    if (a == "son") return "son";//兒子
    if (a == "son_old") return "son";//兒子
    if (a == "son_young") return "son";//兒子
}

string wife(string a) {
    if (a == "dad") return "wife_dad";//妻父
    if (a == "mom") return "wife_mom";//妻母
    if (a == "bro_old") return "wife_bro_old";//妻兄
    if (a == "bro_young") return "wife_bro_young";//妻弟
    if (a == "sis_old") return "wife_sis_old";//妻姊
    if (a == "sis_young") return "wife_sis_young";//妻妹
    if (a == "husband") return "me_male";//我(男)
    //if (a == "wife") { g = 0; return "wife"; }// 我的女兒的媽媽(預設會變成妻子)
    if (a == "daughter") return "daughter";//女兒
    if (a == "daughter_old") return "daughter";//女兒
    if (a == "daughter_young") return "daughter";//女兒
    if (a == "son") return "son";//外孫
    if (a == "son_old") return "son";//外孫
    if (a == "son_young") return "son";//外孫
}

string daughter_old(string a) {
    if (a == "dad" && g == 0) return "me_male";//我(男)
    if (a == "dad" && g == 1) return "husband";//夫
    if (a == "mom" && g == 0) return "wife";//妻
    if (a == "mom" && g == 1) return "me_female";//我(女)
    if (a == "bro_old") return "son";//兒子
    if (a == "bro_young") return "son";//兒子
    if (a == "sis_old") return "daughter";//女兒
    if (a == "sis_young") return "daughter";//女兒
    if (a == "husband") return "daughter_husband";//女婿
    if (a == "daughter") return "daughter_daughter";//外孫
    if (a == "daughter_old") return "daughter_daughter";//外孫
    if (a == "daughter_young") return "daughter_daughter";//外孫
    if (a == "son") return "daughter_son";//外孫
    if (a == "son_old") return "daughter_son";//外孫
    if (a == "son_young") return "daughter_son";//外孫
}

string daughter_young(string a) {
    if (a == "dad" && g == 0) return "me_male";//我(男)
    if (a == "dad" && g == 1) return "husband";//夫
    if (a == "mom" && g == 0) return "wife";//妻
    if (a == "mom" && g == 1) return "me_female";//我(女)
    if (a == "bro_old") return "son";//兒子
    if (a == "bro_young") return "son";//兒子
    if (a == "sis_old") return "daughter";//女兒
    if (a == "sis_young") return "daughter";//女兒
    if (a == "husband") return "daughter_husband";//女婿
    if (a == "daughter") return "daughter_daughter";//外孫
    if (a == "daughter_old") return "daughter_daughter";//外孫
    if (a == "daughter_young") return "daughter_daughter";//外孫
    if (a == "son") return "daughter_son";//外孫
    if (a == "son_old") return "daughter_son";//外孫
    if (a == "son_young") return "daughter_son";//外孫
}

string daughter(string a) {
    if (a == "dad" && g == 0) return "me_male";//我(男)
    if (a == "dad" && g == 1) return "husband";//夫
    if (a == "mom" && g == 0) return "wife";//妻
    if (a == "mom" && g == 1) return "me_female";//我(女)
    if (a == "bro_old") return "son";//兒子
    if (a == "bro_young") return "son";//兒子
    if (a == "sis_old") return "daughter";//女兒
    if (a == "sis_young") return "daughter";//女兒
    if (a == "husband") return "daughter_husband";//女婿
    if (a == "daughter") return "daughter_daughter";//外孫
    if (a == "daughter_old") return "daughter_daughter";//外孫
    if (a == "daughter_young") return "daughter_daughter";//外孫
    if (a == "son") return "daughter_son";//外孫
    if (a == "son_old") return "daughter_son";//外孫
    if (a == "son_young") return "daughter_son";//外孫
}

string son_old(string a) {
    if (a == "dad" && g == 0) return "me_male";//我(男)
    if (a == "dad" && g == 1) return "husband";//夫
    if (a == "mom" && g == 0) return "wife";//妻
    if (a == "mom" && g == 1) return "me_female";//我(女)
    if (a == "bro_old") return "son";//兒子
    if (a == "bro_young") return "son";//兒子
    if (a == "sis_old") return "daughter";//女兒
    if (a == "sis_young") return "daughter";//女兒
    if (a == "wife") return "son_wife";//媳婦
    if (a == "daughter") return "son_daughter";//孫女
    if (a == "daughter_old") return "son_daughter";//孫女
    if (a == "daughter_young") return "son_daughter";//孫女
    if (a == "son") return "son_son";//孫子
    if (a == "son_old") return "son_son";//孫子
    if (a == "son_young") return "son_son";//孫子
}

string son_young(string a) {
    if (a == "dad" && g == 0) return "me_male";//我(男)
    if (a == "dad" && g == 1) return "husband";//夫
    if (a == "mom" && g == 0) return "wife";//妻
    if (a == "mom" && g == 1) return "me_female";//我(女)
    if (a == "bro_old") return "son";//兒子
    if (a == "bro_young") return "son";//兒子
    if (a == "sis_old") return "daughter";//女兒
    if (a == "sis_young") return "daughter";//女兒
    if (a == "wife") return "son_wife";//媳婦
    if (a == "daughter") return "son_daughter";//孫女
    if (a == "daughter_old") return "son_daughter";//孫女
    if (a == "daughter_young") return "son_daughter";//孫女
    if (a == "son") return "son_son";//孫子
    if (a == "son_old") return "son_son";//孫子
    if (a == "son_young") return "son_son";//孫子
}

string son(string a) {
    if (a == "dad" && g == 0) return "me_male";//我(男)
    if (a == "dad" && g == 1) return "husband";//夫
    if (a == "mom" && g == 0) return "wife";//妻
    if (a == "mom" && g == 1) return "me_female";//我(女)
    if (a == "bro_old") return "son";//兒子
    if (a == "bro_young") return "son";//兒子
    if (a == "sis_old") return "daughter";//女兒
    if (a == "sis_young") return "daughter";//女兒
    if (a == "wife") return "son_wife";//媳婦
    if (a == "daughter") return "son_daughter";//孫女
    if (a == "daughter_old") return "son_daughter";//孫女
    if (a == "daughter_young") return "son_daughter";//孫女
    if (a == "son") return "son_son";//孫子
    if (a == "son_old") return "son_son";//孫子
    if (a == "son_young") return "son_son";//孫子
}

string me_female(string a) {
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "bro_old";//哥哥
    if (a == "bro_young") return "bro_young";//弟弟
    if (a == "sis_old") return "sis_old";//姊姊
    if (a == "sis_young") return "sis_young";//妹妹
    if (a == "husband") return "husband";//夫
    if (a == "daughter") return "daughter";//女兒
    if (a == "daughter_old") return "daughter";//女兒
    if (a == "daughter_young") return "daughter";//女兒
    if (a == "son") return "son";//兒子
    if (a == "son_old") return "son";//兒子
    if (a == "son_young") return "son";//兒子
}

string me_male(string a) {
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "bro_old";//哥哥
    if (a == "bro_young") return "bro_young";//弟弟
    if (a == "sis_old") return "sis_old";//姊姊
    if (a == "sis_young") return "sis_young";//妹妹
    if (a == "wife") return "wife";//妻
    if (a == "daughter") return "daughter";//女兒
    if (a == "daughter_old") return "daughter";//女兒
    if (a == "daughter_young") return "daughter";//女兒
    if (a == "son") return "son";//兒子
    if (a == "son_old") return "son";//兒子
    if (a == "son_young") return "son";//兒子
}

string me(string a) {
    if (a == "dad") return "dad";//父親
    if (a == "mom") return "mom";//母親
    if (a == "bro_old") return "bro_old";//哥哥
    if (a == "bro_young") return "bro_young";//弟弟
    if (a == "sis_old") return "sis_old";//姊姊
    if (a == "sis_young") return "sis_young";//妹妹
    if (a == "husband") { g = 1; return "husband"; }//夫 -------add
    if (a == "wife") { g = 0; return "wife"; }//妻 -------------add
    if (a == "daughter") return "daughter";//女兒
    if (a == "daughter_old") return "daughter";//女兒
    if (a == "daughter_young") return "daughter";//女兒
    if (a == "son") return "son";//兒子
    if (a == "son_old") return "son";//兒子
    if (a == "son_young") return "son";//兒子
}

string dad_dad(string a) {
    if (a == "dad") return "dad_dad_dad";//阿祖
    if (a == "mom") return "dad_dad_mom";//阿祖
    if (a == "bro_old") return "";//
    if (a == "bro_young") return "";//
    if (a == "sis_old") return "";//
    if (a == "sis_young") return "";//
    if (a == "wife") return "dad_mom";//祖母
    if (a == "daughter") return "dad_sis_old";//姑媽
    if (a == "daughter_old") return "dad_sis_old";//姑媽
    if (a == "daughter_young") return "dad_sis_young";//姑媽
    if (a == "son") return "dad";//父親(預設)
    if (a == "son_old") return "dad_bro_old";//伯父
    if (a == "son_young") return "dad_bro_young";//叔父
}
string dad_mom(string a) {
    if (a == "dad") return "dad_dad_dad";//阿祖
    if (a == "mom") return "dad_dad_mom";//阿祖
    if (a == "bro_old") return "";//
    if (a == "bro_young") return "";//
    if (a == "sis_old") return "";//
    if (a == "sis_young") return "";//
    if (a == "husband") return "dad_dad";//祖父
    if (a == "daughter") return "dad_sis_old";//姑媽
    if (a == "daughter_old") return "dad_sis_old";//姑媽
    if (a == "daughter_young") return "dad_sis_young";//姑媽
    if (a == "son") return "dad";//父親(預設)
    if (a == "son_old") return "dad_bro_old";//伯父
    if (a == "son_young") return "dad_bro_young";//叔父
}

string dad_bro_old(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "bro_old") return "dad_bro_old";//
    if (a == "bro_young") return "dad";//父親(預設)
    if (a == "sis_old") return "dad_sis_old";//姑媽
    if (a == "sis_young") return "dad_sis_young";//姑媽
    if (a == "wife") return "dad_bro_old_wife";//伯母
    if (a == "daughter") return "dad_bro_old_daughter_old";//堂姊
    if (a == "daughter_old") return "dad_bro_old_daughter_old";//堂姊
    if (a == "daughter_young") return "dad_bro_old_daughter_young";//堂妹
    if (a == "son") return "dad_bro_old_son_old";//堂哥
    if (a == "son_old") return "dad_bro_old_son_old";//堂哥
    if (a == "son_young") return "dad_bro_old_son_young";//堂弟
}
string dad_bro_young(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "bro_old") return "dad";//父親(預設)
    if (a == "bro_young") return "dad_bro_young";//
    if (a == "sis_old") return "dad_sis_old";//姑媽
    if (a == "sis_young") return "dad_sis_young";//姑媽
    if (a == "wife") return "dad_bro_young_wife";//嬸嬸
    if (a == "daughter") return "dad_bro_young_daughter_old";//堂姊
    if (a == "daughter_old") return "dad_bro_young_daughter_old";//堂姊
    if (a == "daughter_young") return "dad_bro_young_daughter_young";//堂妹
    if (a == "son") return "dad_bro_young_son_old";//堂哥
    if (a == "son_old") return "dad_bro_young_son_old";//堂哥
    if (a == "son_young") return "dad_bro_young_son_young";//堂弟
}
string dad_sis_old(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "bro_old") return "dad";//父親(預設)
    if (a == "bro_young") return "dad";//父親(預設)
    if (a == "sis_old") return "dad_sis_old";//姑媽(預設)
    if (a == "sis_young") return "dad_sis_young";//姑媽(預設)
    if (a == "husband") return "dad_sis_old_husband";//姑丈
    if (a == "daughter") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//表妹
    if (a == "son") return "dad_sis_old_son_old";//表兄
    if (a == "son_old") return "dad_sis_old_son_old";//表兄
    if (a == "son_young") return "dad_sis_old_son_young";//表弟
}
string dad_sis_young(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "bro_old") return "dad";//父親(預設)
    if (a == "bro_young") return "dad";//父親(預設)
    if (a == "sis_old") return "dad_sis_old";//姑媽(預設)
    if (a == "sis_young") return "dad_sis_young";//姑媽(預設)
    if (a == "husband") return "dad_sis_young_husband";//姑丈
    if (a == "daughter") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//表妹
    if (a == "son") return "dad_sis_old_son_old";//表兄
    if (a == "son_old") return "dad_sis_old_son_old";//表兄
    if (a == "son_young") return "dad_sis_old_son_young";//表弟
}

string dad_bro_old_wife(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "husband") return "dad_bro_old";//伯父
    if (a == "daughter") return "dad_bro_old_daughter_old";//堂姊
    if (a == "daughter_old") return "dad_bro_old_daughter_old";//堂姊
    if (a == "daughter_young") return "dad_bro_old_daughter_young";//堂妹
    if (a == "son") return "dad_bro_old_son_old";//堂哥
    if (a == "son_old") return "dad_bro_old_son_old";//堂哥
    if (a == "son_young") return "dad_bro_old_son_young";//堂弟
}
string dad_bro_young_wife(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "husband") return "dad_bro_young";//叔父
    if (a == "daughter") return "dad_bro_young_daughter_old";//堂姊
    if (a == "daughter_old") return "dad_bro_young_daughter_old";//堂姊
    if (a == "daughter_young") return "dad_bro_young_daughter_young";//堂妹
    if (a == "son") return "dad_bro_young_son_old";//堂哥
    if (a == "son_old") return "dad_bro_young_son_old";//堂哥
    if (a == "son_young") return "dad_bro_young_son_young";//堂弟
}
string dad_sis_old_husband(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "wife") return "dad_sis_old";//姑媽
    if (a == "daughter") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//表妹
    if (a == "son") return "dad_sis_old_son_old";//表兄
    if (a == "son_old") return "dad_sis_old_son_old";//表兄
    if (a == "son_young") return "dad_sis_old_son_young";//表弟
}
string dad_sis_young_husband(string a) {
    if (a == "dad") return "dad_dad";//祖父
    if (a == "mom") return "dad_mom";//祖母
    if (a == "wife") return "dad_sis_old";//姑媽
    if (a == "daughter") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//表妹
    if (a == "son") return "dad_sis_old_son_old";//表兄
    if (a == "son_old") return "dad_sis_old_son_old";//表兄
    if (a == "son_young") return "dad_sis_old_son_young";//表弟
}

string dad_bro_old_daughter_old(string a) {
    if (a == "dad") return "dad_bro_old";//伯父
    if (a == "mom") return "dad_bro_old_wife";//伯母
    if (a == "bro_old") return "dad_bro_old_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_old_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_old_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_old_daughter_young";//堂妹
}
string dad_bro_old_daughter_young(string a) {
    if (a == "dad") return "dad_bro_old";//伯父
    if (a == "mom") return "dad_bro_old_wife";//伯母
    if (a == "bro_old") return "dad_bro_old_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_old_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_old_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_old_daughter_young";//堂妹
}
string dad_bro_old_son_old(string a) {
    if (a == "dad") return "dad_bro_old";//伯父
    if (a == "mom") return "dad_bro_old_wife";//伯母
    if (a == "bro_old") return "dad_bro_old_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_old_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_old_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_old_daughter_young";//堂姊
}
string dad_bro_old_son_young(string a) {
    if (a == "dad") return "dad_bro_old";//伯父
    if (a == "mom") return "dad_bro_old_wife";//伯母
    if (a == "bro_old") return "dad_bro_old_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_old_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_old_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_old_daughter_young";//堂妹
}
string dad_bro_young_daughter_old(string a) {
    if (a == "dad") return "dad_bro_young";//叔父
    if (a == "mom") return "dad_bro_young_wife";//嬸嬸
    if (a == "bro_old") return "dad_bro_young_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_young_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_young_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_young_daughter_young";//堂妹
}
string dad_bro_young_daughter_young(string a) {
    if (a == "dad") return "dad_bro_young";//叔父
    if (a == "mom") return "dad_bro_young_wife";//嬸嬸
    if (a == "bro_old") return "dad_bro_young_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_young_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_young_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_young_daughter_young";//堂妹
}
string dad_bro_young_son_old(string a) {
    if (a == "dad") return "dad_bro_young";//叔父
    if (a == "mom") return "dad_bro_young_wife";//嬸嬸
    if (a == "bro_old") return "dad_bro_young_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_young_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_young_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_young_daughter_young";//堂妹
}
string dad_bro_young_son_young(string a) {
    if (a == "dad") return "dad_bro_young";//叔父
    if (a == "mom") return "dad_bro_young_wife";//嬸嬸
    if (a == "bro_old") return "dad_bro_young_son_old";//堂哥
    if (a == "bro_young") return "dad_bro_young_son_young";//堂弟
    if (a == "sis_old") return "dad_bro_young_daughter_old";//堂姊
    if (a == "sis_young") return "dad_bro_young_daughter_young";//堂妹
}
string dad_sis_old_daughter_old(string a) {
    if (a == "dad") return "dad_sis_old_husband";//叔父
    if (a == "mom") return "dad_sis_old";//叔母
    if (a == "bro_old") return "dad_sis_old_son_old";//表哥
    if (a == "bro_young") return "dad_sis_old_son_young";//表弟
    if (a == "sis_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "sis_young") return "dad_sis_old_daughter_young";//表妹
}
string dad_sis_old_daughter_young(string a) {
    if (a == "dad") return "dad_sis_old_husband";//叔父
    if (a == "mom") return "dad_sis_old";//叔母
    if (a == "bro_old") return "dad_sis_old_son_old";//表哥
    if (a == "bro_young") return "dad_sis_old_son_young";//表弟
    if (a == "sis_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "sis_young") return "dad_sis_old_daughter_young";//表妹
}
string dad_sis_old_son_old(string a) {
    if (a == "dad") return "dad_sis_old_husband";//叔父
    if (a == "mom") return "dad_sis_old";//叔母
    if (a == "bro_old") return "dad_sis_old_son_old";//表哥
    if (a == "bro_young") return "dad_sis_old_son_young";//表弟
    if (a == "sis_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "sis_young") return "dad_sis_old_daughter_young";//表妹
}
string dad_sis_old_son_young(string a) {
    if (a == "dad") return "dad_sis_old_husband";//叔父
    if (a == "mom") return "dad_sis_old";//叔母
    if (a == "bro_old") return "dad_sis_old_son_old";//表哥
    if (a == "bro_young") return "dad_sis_old_son_young";//表弟
    if (a == "sis_old") return "dad_sis_old_daughter_old";//表姊
    if (a == "sis_young") return "dad_sis_old_daughter_young";//表妹
}
bool m = 0;
string mom_dad(string a) {
    if (a == "wife") return "mom_mom";//外祖母
    if (a == "daughter") return "mom_sis_old";//母親(預設)
    if (a == "daughter" && m ==1) return "mom";//母親(預設)
    if (a == "daughter_old") return "mom_sis_old";//姨媽
    if (a == "daughter_young") return "mom_sis_young";//姨媽
    if (a == "son") return "mom_bro_old";//舅舅
    if (a == "son_old") return "mom_bro_old";//舅舅
    if (a == "son_young") return "mom_bro_old";//舅舅
}
string mom_mom(string a) {
    if (a == "husband") return "mom_dad";//外祖父
    if (a == "daughter") return "mom_sis_old";//母親(預設)
    if (a == "daughter" && m ==1) return "mom";//母親(預設)
    if (a == "daughter_old") return "mom_sis_old";//姨媽
    if (a == "daughter_young") return "mom_sis_young";//姨媽
    if (a == "son") return "mom_bro_old";//舅舅
    if (a == "son_old") return "mom_bro_old";//舅舅
    if (a == "son_young") return "mom_bro_old";//舅舅
}

string mom_bro_old(string a) {
    if (a == "dad") return "mom_dad";//外祖父
    if (a == "mom") return "mom_mom";//外祖母
    if (a == "bro_old") return "mom_bro_old";//舅舅
    if (a == "bro_young") return "mom_bro_young";//舅舅
    if (a == "sis_old") return "mom";//姨媽
    if (a == "sis_young") return "mom";//母親(預設)
    if (a == "wife") return "mom_bro_old_wife";//舅媽
    if (a == "daughter") return "mom_bro_old_daughter_old";//表姊
    if (a == "daughter_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "daughter_young") return "mom_bro_old_daughter_young";//表妹
    if (a == "son") return "mom_bro_old_son_old";//表哥
    if (a == "son_old") return "mom_bro_old_son_old";//表哥
    if (a == "son_young") return "mom_bro_old_son_young";//表弟
}
string mom_bro_young(string a) {
    if (a == "dad") return "mom_dad";//外祖父
    if (a == "mom") return "mom_mom";//外祖母
    if (a == "bro_old") return "mom_bro_old";//舅舅
    if (a == "bro_young") return "mom_bro_young";//舅舅
    if (a == "sis_old") return "mom";//姨媽
    if (a == "sis_young") return "mom";//母親(預設)
    if (a == "wife") return "mom_bro_old_wife";//舅媽
    if (a == "daughter") return "mom_bro_old_daughter_old";//表姊
    if (a == "daughter_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "daughter_young") return "mom_bro_old_daughter_young";//表妹
    if (a == "son") return "mom_bro_old_son_old";//表哥
    if (a == "son_old") return "mom_bro_old_son_old";//表哥
    if (a == "son_young") return "mom_bro_old_son_young";//表弟
}
string mom_sis_old(string a) {
    if (a == "dad") return "mom_dad";//外祖父
    if (a == "mom") return "mom_mom";//外祖母
    if (a == "bro_old") return "mom_bro_old";//舅舅
    if (a == "bro_young") return "mom_bro_old";//舅舅
    if (a == "sis_old") return "mom_sis_old";//姨媽
    if (a == "sis_young") return "mom";//母親(預設)
    if (a == "husband") return "mom_sis_old_husband";//姨丈
    if (a == "daughter") return "mom_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "mom_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "mom_sis_old_daughter_young";//表妹
    if (a == "son") return "mom_sis_old_son_old";//表哥
    if (a == "son_old") return "mom_sis_old_son_old";//表哥
    if (a == "son_young") return "mom_sis_old_son_young";//表弟
}
string mom_sis_young(string a) {
    if (a == "dad") return "mom_dad";//外祖父
    if (a == "mom") return "mom_mom";//外祖母
    if (a == "bro_old") return "mom_bro_old";//舅舅
    if (a == "bro_young") return "mom_bro_old";//舅舅
    if (a == "sis_old") return "mom";//姨媽
    if (a == "sis_young") return "mom_sis_young";//母親(預設)
    if (a == "husband") return "mom_sis_old_husband";//姨丈
    if (a == "daughter") return "mom_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "mom_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "mom_sis_old_daughter_young";//表妹
    if (a == "son") return "mom_sis_old_son_old";//表哥
    if (a == "son_old") return "mom_sis_old_son_old";//表哥
    if (a == "son_young") return "mom_sis_old_son_young";//表弟
}
string mom_bro_old_wife(string a) {
    if (a == "husband") return "mom_bro_old";//舅舅
    if (a == "daughter") return "mom_bro_old_daughter_old";//表姊
    if (a == "daughter_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "daughter_young") return "mom_bro_old_daughter_young";//表妹
    if (a == "son") return "mom_bro_old_son_old";//表哥
    if (a == "son_old") return "mom_bro_old_son_old";//表哥
    if (a == "son_young") return "mom_bro_old_son_young";//表弟
}
string mom_sis_old_husband(string a) {
    if (a == "wife") return "mom_sis_old";//姨媽
    if (a == "daughter") return "mom_sis_old_daughter_old";//表姊
    if (a == "daughter_old") return "mom_sis_old_daughter_old";//表姊
    if (a == "daughter_young") return "mom_sis_old_daughter_young";//表妹
    if (a == "son") return "mom_sis_old_son_old";//表哥
    if (a == "son_old") return "mom_sis_old_son_old";//表哥
    if (a == "son_young") return "mom_sis_old_son_young";//表弟
}

string mom_bro_old_daughter_old(string a) {
    if (a == "dad") return "mom_bro_old";//舅舅
    if (a == "mom") return "mom_bro_old_wife";//舅媽
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_bro_old_daughter_young(string a) {
    if (a == "dad") return "mom_bro_old";//舅舅
    if (a == "mom") return "mom_bro_old_wife";//舅媽
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_bro_old_son_old(string a) {
    if (a == "dad") return "mom_bro_old";//舅舅
    if (a == "mom") return "mom_bro_old_wife";//舅媽
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_bro_old_son_young(string a) {
    if (a == "dad") return "mom_bro_old";//舅舅
    if (a == "mom") return "mom_bro_old_wife";//舅媽
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_sis_old_daughter_old(string a) {
    if (a == "mom") return "mom_sis_old";//姨媽
    if (a == "dad") return "mom_sis_old_husband";//姨丈
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_sis_old_daughter_young(string a) {
    if (a == "mom") return "mom_sis_old";//姨媽
    if (a == "dad") return "mom_sis_old_husband";//姨丈
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_sis_old_son_old(string a) {
    if (a == "mom") return "mom_sis_old";//姨媽
    if (a == "dad") return "mom_sis_old_husband";//姨丈
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}
string mom_sis_old_son_young(string a) {
    if (a == "mom") return "mom_sis_old";//姨媽
    if (a == "dad") return "mom_sis_old_husband";//姨丈
    if (a == "bro_old") return "mom_bro_old_son_old";//表哥
    if (a == "bro_young") return "mom_bro_old_son_young";//表弟
    if (a == "sis_old") return "mom_bro_old_daughter_old";//表姊
    if (a == "sis_young") return "mom_bro_old_daughter_young";//表妹
}

string bro_old_wife(string a) {
    if (a == "husband") return "bro_old";//哥哥
    if (a == "daughter") return "bro_old_daughter";//姪女
    if (a == "daughter_old") return "bro_old_daughter";//姪女
    if (a == "daughter_young") return "bro_old_daughter";//姪女
    if (a == "son") return "bro_old_son";//姪子
    if (a == "son_old") return "bro_old_son";//姪子
    if (a == "son_young") return "bro_old_son";//姪子
}
string bro_old_daughter(string a) {
    if (a == "dad") return "bro_old";//哥哥
    if (a == "mom") return "bro_old_wife";//嫂嫂
    if (a == "bro_old") return "bro_old_son";//姪子
    if (a == "bro_young") return "bro_old_son";//姪子
    if (a == "sis_old") return "bro_old_daughter";//姪女
    if (a == "sis_young") return "bro_old_daughter";//姪女
}
string bro_old_son(string a) {
    if (a == "dad") return "bro_old";//哥哥
    if (a == "mom") return "bro_old_wife";//嫂嫂
    if (a == "bro_old") return "bro_old_son";//姪子
    if (a == "bro_young") return "bro_old_son";//姪子
    if (a == "sis_old") return "bro_old_daughter";//姪女
    if (a == "sis_young") return "bro_old_daughter";//姪女
}

string bro_young_wife(string a) {
    if (a == "husband") return "bro_young";//弟弟
    if (a == "daughter") return "bro_young_daughter";//姪女
    if (a == "daughter_old") return "bro_young_daughter";//姪女
    if (a == "daughter_young") return "bro_young_daughter";//姪女
    if (a == "son") return "bro_young_son";//姪子
    if (a == "son_old") return "bro_young_son";//姪子
    if (a == "son_young") return "bro_young_son";//姪子
}
string bro_young_daughter(string a) {
    if (a == "dad") return "bro_young";//弟弟
    if (a == "mom") return "bro_young_wife";//弟媳
    if (a == "bro_old") return "bro_young_son";//姪子
    if (a == "bro_young") return "bro_young_son";//姪子
    if (a == "sis_old") return "bro_young_daughter";//姪女
    if (a == "sis_young") return "bro_young_daughter";//姪女
}
string bro_young_son(string a) {
    if (a == "dad") return "bro_young";//弟弟
    if (a == "mom") return "bro_young_wife";//弟媳
    if (a == "bro_old") return "bro_young_son";//姪子
    if (a == "bro_young") return "bro_young_son";//姪子
    if (a == "sis_old") return "bro_young_daughter";//姪女
    if (a == "sis_young") return "bro_young_daughter";//姪女
}

string sis_old_husband(string a) {
    if (a == "wife") return "sis_old";//姊姊
    if (a == "daughter") return "sis_old_daughter";//外甥女
    if (a == "daughter_old") return "sis_old_daughter";//外甥女
    if (a == "daughter_young") return "sis_old_daughter";//外甥女
    if (a == "son") return "sis_old_son";//外甥
    if (a == "son_old") return "sis_old_son";//外甥
    if (a == "son_young") return "sis_old_son";//外甥
}
string sis_old_daughter(string a) {
    if (a == "dad") return "sis_old_husband";//姊夫
    if (a == "mom") return "sis_old";//姊姊
    if (a == "bro_old") return "sis_old_son";//外甥
    if (a == "bro_young") return "sis_old_son";//外甥
    if (a == "sis_old") return "sis_old_daughter";//外甥女
    if (a == "sis_young") return "sis_old_daughter";//外甥女
}
string sis_old_son(string a) {
    if (a == "dad") return "sis_old_husband";//姊夫
    if (a == "mom") return "sis_old";//姊姊
    if (a == "bro_old") return "sis_old_son";//外甥
    if (a == "bro_young") return "sis_old_son";//外甥
    if (a == "sis_old") return "sis_old_daughter";//外甥女
    if (a == "sis_young") return "sis_old_daughter";//外甥女
}

string sis_young_husband(string a) {
    if (a == "wife") return "sis_young";//妹妹
    if (a == "daughter") return "sis_young_daughter";//外甥女
    if (a == "daughter_old") return "sis_young_daughter";//外甥女
    if (a == "daughter_young") return "sis_young_daughter";//外甥女
    if (a == "son") return "sis_young_son";//外甥
    if (a == "son_old") return "sis_young_son";//外甥
    if (a == "son_young") return "sis_young_son";//外甥
}
string sis_young_daughter(string a) {
    if (a == "dad") return "sis_young_husband";//妹夫
    if (a == "mom") return "sis_young";//妹妹
    if (a == "bro_old") return "sis_young_son";//外甥
    if (a == "bro_young") return "sis_young_son";//外甥
    if (a == "sis_old") return "sis_young_daughter";//外甥女
    if (a == "sis_young") return "sis_young_daughter";//外甥女
}
string sis_young_son(string a) {
    if (a == "dad") return "sis_young_husband";//妹夫
    if (a == "mom") return "sis_young";//妹妹
    if (a == "bro_old") return "sis_young_son";//外甥
    if (a == "bro_young") return "sis_young_son";//外甥
    if (a == "sis_old") return "sis_young_daughter";//外甥女
    if (a == "sis_young") return "sis_young_daughter";//外甥女
}

string husband_dad(string a) {
    if (a == "wife") return "husband_mom";//夫母
    if (a == "daughter") return "husband_sis_old";//夫姊
    if (a == "daughter_old") return "husband_sis_old";//夫姊
    if (a == "daughter_young") return "husband_sis_young";//夫妹
    if (a == "son") return "husband";//夫
    if (a == "son_old") return "husband_bro_old";//夫兄
    if (a == "son_young") return "husband_bro_young";//夫弟
}
string husband_mom(string a) {
    if (a == "husband") return "husband_dad";//夫父
    if (a == "daughter") return "husband_sis_old";//夫姊
    if (a == "daughter_old") return "husband_sis_old";//夫姊
    if (a == "daughter_young") return "husband_sis_young";//夫妹
    if (a == "son") return "husband";//夫
    if (a == "son_old") return "husband_bro_old";//夫兄
    if (a == "son_young") return "husband_bro_young";//夫弟
}

string husband_bro_old(string a) {
    if (a == "dad") return "husband_dad";//夫父
    if (a == "mom") return "husband_mom";//夫母
    if (a == "bro_old") return "husband_bro_old";//夫兄
    if (a == "bro_young") return "husband";//夫
    if (a == "sis_old") return "husband_sis_old";//夫姊
    if (a == "sis_young") return "husband_sis_young";//夫妹
    if (a == "wife") return "husband_bro_old_wife";//夫兄嫂
    if (a == "daughter") return "husband_bro_old_daughter";//姪女
    if (a == "daughter_old") return "husband_bro_old_daughter";//姪女
    if (a == "daughter_young") return "husband_bro_old_daughter";//姪女
    if (a == "son") return "husband_bro_old_son";//姪子
    if (a == "son_old") return "husband_bro_old_son";//姪子
    if (a == "son_young") return "husband_bro_old_son";//姪子
}
string husband_bro_young(string a) {
    if (a == "dad") return "husband_dad";//夫父
    if (a == "mom") return "husband_mom";//夫母
    if (a == "bro_old") return "husband";//夫
    if (a == "bro_young") return "husband_bro_young";//夫弟
    if (a == "sis_old") return "husband_sis_old";//夫姊
    if (a == "sis_young") return "husband_sis_young";//夫妹
    if (a == "wife") return "husband_bro_young_wife";//夫弟媳
    if (a == "daughter") return "husband_bro_young_daughter";//姪女
    if (a == "daughter_old") return "husband_bro_young_daughter";//姪女
    if (a == "daughter_young") return "husband_bro_young_daughter";//姪女
    if (a == "son") return "husband_bro_young_son";//姪子
    if (a == "son_old") return "husband_bro_young_son";//姪子
    if (a == "son_young") return "husband_bro_young_son";//姪子
}
string husband_sis_old(string a) {
    if (a == "dad") return "husband_dad";//夫父
    if (a == "mom") return "husband_mom";//夫母
    if (a == "bro_old") return "husband_bro_old";//夫兄
    if (a == "bro_young") return "husband_bro_young";//夫弟
    if (a == "sis_old") return "husband_sis_old";//夫姊
    if (a == "sis_young") return "husband_sis_young";//夫妹
    if (a == "husband") return "husband_sis_old_husband";//夫姊夫
    if (a == "daughter") return "husband_sis_old_daughter";//外甥女
    if (a == "daughter_old") return "husband_sis_old_daughter";//外甥女
    if (a == "daughter_young") return "husband_sis_old_daughter";//外甥女
    if (a == "son") return "husband_sis_old_son";//外甥
    if (a == "son_old") return "husband_sis_old_son";//外甥
    if (a == "son_young") return "husband_sis_old_son";//外甥
}
string husband_sis_young(string a) {
    if (a == "dad") return "husband_dad";//夫父
    if (a == "mom") return "husband_mom";//夫母
    if (a == "bro_old") return "husband_bro_old";//夫兄
    if (a == "bro_young") return "husband_bro_young";//夫弟
    if (a == "sis_old") return "husband_sis_old";//夫姊
    if (a == "sis_young") return "husband_sis_young";//夫妹
    if (a == "husband") return "husband_sis_young_husband";//夫妹夫
    if (a == "daughter") return "husband_sis_young_daughter";//外甥女
    if (a == "daughter_old") return "husband_sis_young_daughter";//外甥女
    if (a == "daughter_young") return "husband_sis_young_daughter";//外甥女
    if (a == "son") return "husband_sis_young_son";//外甥
    if (a == "son_old") return "husband_sis_young_son";//外甥
    if (a == "son_young") return "husband_sis_young_son";//外甥
}

string husband_bro_old_wife(string a) {
    if (a == "husband") return "husband_bro_old";//夫兄
    if (a == "daughter") return "husband_bro_old_daughter";//姪女
    if (a == "daughter_old") return "husband_bro_old_daughter";//姪女
    if (a == "daughter_young") return "husband_bro_old_daughter";//姪女
    if (a == "son") return "husband_bro_old_son";//姪子
    if (a == "son_old") return "husband_bro_old_son";//姪子
    if (a == "son_young") return "husband_bro_old_son";//姪子
}
string husband_bro_young_wife(string a) {
    if (a == "husband") return "husband_bro_young";//夫弟
    if (a == "daughter") return "husband_bro_young_daughter";//姪女
    if (a == "daughter_old") return "husband_bro_young_daughter";//姪女
    if (a == "daughter_young") return "husband_bro_young_daughter";//姪女
    if (a == "son") return "husband_bro_young_son";//姪子
    if (a == "son_old") return "husband_bro_young_son";//姪子
    if (a == "son_young") return "husband_bro_young_son";//姪子
}
string husband_sis_old_husband(string a) {
    if (a == "wife") return "husband_sis_old";//夫姊
    if (a == "daughter") return "husband_sis_old_daughter";//外甥女
    if (a == "daughter_old") return "husband_sis_old_daughter";//外甥女
    if (a == "daughter_young") return "husband_sis_old_daughter";//外甥女
    if (a == "son") return "husband_sis_old_son";//外甥
    if (a == "son_old") return "husband_sis_old_son";//外甥
    if (a == "son_young") return "husband_sis_old_son";//外甥
}
string husband_sis_young_husband(string a) {
    if (a == "wife") return "husband_sis_young";//夫妹
    if (a == "daughter") return "husband_sis_young_daughter";//外甥女
    if (a == "daughter_old") return "husband_sis_young_daughter";//外甥女
    if (a == "daughter_young") return "husband_sis_young_daughter";//外甥女
    if (a == "son") return "husband_sis_young_son";//外甥
    if (a == "son_old") return "husband_sis_young_son";//外甥
    if (a == "son_young") return "husband_sis_young_son";//外甥
}

string husband_bro_old_daughter(string a) {
    if (a == "dad") return "husband_bro_old";//夫兄
    if (a == "mom") return "husband_bro_old_wife";//夫兄嫂
    if (a == "bro_old") return "husband_bro_old_son";//姪子
    if (a == "bro_young") return "husband_bro_old_son";//姪子
    if (a == "sis_old") return "husband_bro_old_daughter";//姪女
    if (a == "sis_young") return "husband_bro_old_daughter";//姪女
}
string husband_bro_old_son(string a) {
    if (a == "dad") return "husband_bro_old";//夫兄
    if (a == "mom") return "husband_bro_old_wife";//夫兄嫂
    if (a == "bro_old") return "husband_bro_old_son";//姪子
    if (a == "bro_young") return "husband_bro_old_son";//姪子
    if (a == "sis_old") return "husband_bro_old_daughter";//姪女
    if (a == "sis_young") return "husband_bro_old_daughter";//姪女
}
string husband_bro_young_daughter(string a) {
    if (a == "dad") return "husband_bro_young";//夫弟
    if (a == "mom") return "husband_bro_young_wife";//夫弟媳
    if (a == "bro_old") return "husband_bro_young_son";//姪子
    if (a == "bro_young") return "husband_bro_young_son";//姪子
    if (a == "sis_old") return "husband_bro_young_daughter";//姪女
    if (a == "sis_young") return "husband_bro_young_daughter";//姪女
}
string husband_bro_young_son(string a) {
    if (a == "dad") return "husband_bro_young";//夫弟
    if (a == "mom") return "husband_bro_young_wife";//夫弟媳
    if (a == "bro_old") return "husband_bro_young_son";//姪子
    if (a == "bro_young") return "husband_bro_young_son";//姪子
    if (a == "sis_old") return "husband_bro_young_daughter";//姪女
    if (a == "sis_young") return "husband_bro_young_daughter";//姪女
}
string husband_sis_old_daughter(string a) {
    if (a == "dad") return "husband_sis_old_husband";//夫姊夫
    if (a == "mom") return "husband_sis_old";//夫姊
    if (a == "bro_old") return "husband_sis_old_son";//外甥
    if (a == "bro_young") return "husband_sis_old_son";//外甥
    if (a == "sis_old") return "husband_sis_old_daughter";//外甥女
    if (a == "sis_young") return "husband_sis_old_daughter";//外甥女
}
string husband_sis_old_son(string a) {
    if (a == "dad") return "husband_sis_old_husband";//夫姊夫
    if (a == "mom") return "husband_sis_old";//夫姊
    if (a == "bro_old") return "husband_sis_old_son";//外甥
    if (a == "bro_young") return "husband_sis_old_son";//外甥
    if (a == "sis_old") return "husband_sis_old_daughter";//外甥女
    if (a == "sis_young") return "husband_sis_old_daughter";//外甥女
}
string husband_sis_young_daughter(string a) {
    if (a == "dad") return "husband_sis_young_husband";//夫妹夫
    if (a == "mom") return "husband_sis_young";//夫妹
    if (a == "bro_old") return "husband_sis_young_son";//外甥
    if (a == "bro_young") return "husband_sis_young_son";//外甥
    if (a == "sis_old") return "husband_sis_young_daughter";//外甥女
    if (a == "sis_young") return "husband_sis_young_daughter";//外甥女
}
string husband_sis_young_son(string a) {
    if (a == "dad") return "husband_sis_young_husband";//夫妹夫
    if (a == "mom") return "husband_sis_young";//夫妹
    if (a == "bro_old") return "husband_sis_young_son";//外甥
    if (a == "bro_young") return "husband_sis_young_son";//外甥
    if (a == "sis_old") return "husband_sis_young_daughter";//外甥女
    if (a == "sis_young") return "husband_sis_young_daughter";//外甥女
}

string wife_dad(string a) {
    if (a == "wife") return "wife_mom";//妻母
    if (a == "daughter") return "wife";//妻
    if (a == "daughter_old") return "wife_sis_old";//妻姊
    if (a == "daughter_young") return "wife_sis_young";//妻妹
    if (a == "son") return "wife_bro_old";//妻兄
    if (a == "son_old") return "wife_bro_old";//妻兄
    if (a == "son_young") return "wife_bro_young";//妻弟
}
string wife_mom(string a) {
    if (a == "husband") return "wife_dad";//妻父
    if (a == "daughter") return "wife";//妻
    if (a == "daughter_old") return "wife_sis_old";//妻姊
    if (a == "daughter_young") return "wife_sis_young";//妻妹
    if (a == "son") return "wife_bro_old";//妻兄
    if (a == "son_old") return "wife_bro_old";//妻兄
    if (a == "son_young") return "wife_bro_young";//妻弟
}

string wife_bro_old(string a) {
    if (a == "dad") return "wife_dad";//妻父
    if (a == "mom") return "wife_mom";//妻母
    if (a == "bro_old") return "wife_bro_old";//妻兄
    if (a == "bro_young") return "wife_bro_young";//妻弟
    if (a == "sis_old") return "wife_sis_old";//妻姊
    if (a == "sis_young") return "wife";//妻
    if (a == "wife") return "wife_bro_old_wife";//妻兄嫂
    if (a == "daughter") return "wife_bro_old_daughter";//外甥女
    if (a == "daughter_old") return "wife_bro_old_daughter";//外甥女
    if (a == "daughter_young") return "wife_bro_old_daughter";//外甥女
    if (a == "son") return "wife_bro_old_son";//外甥
    if (a == "son_old") return "wife_bro_old_son";//外甥
    if (a == "son_young") return "wife_bro_old_son";//外甥
}
string wife_bro_young(string a) {
    if (a == "dad") return "wife_dad";//妻父
    if (a == "mom") return "wife_mom";//妻母
    if (a == "bro_old") return "wife_bro_old";//妻兄
    if (a == "bro_young") return "wife_bro_young";//妻弟
    if (a == "sis_old") return "wife";//妻
    if (a == "sis_young") return "wife_sis_young";//妻妹
    if (a == "wife") return "wife_bro_young_wife";//妻弟媳
    if (a == "daughter") return "wife_bro_young_daughter";//外甥女
    if (a == "daughter_old") return "wife_bro_young_daughter";//外甥女
    if (a == "daughter_young") return "wife_bro_young_daughter";//外甥女
    if (a == "son") return "wife_bro_young_son";//外甥
    if (a == "son_old") return "wife_bro_young_son";//外甥
    if (a == "son_young") return "wife_bro_young_son";//外甥
}
string wife_sis_old(string a) {
    if (a == "dad") return "wife_dad";//妻父
    if (a == "mom") return "wife_mom";//妻母
    if (a == "bro_old") return "wife_bro_old";//妻兄
    if (a == "bro_young") return "wife_bro_young";//妻弟
    if (a == "sis_old") return "wife_sis_old";//妻姊
    if (a == "sis_young") return "wife";//妻
    if (a == "husband") return "wife_sis_old_husband";//妻姊夫
    if (a == "daughter") return "wife_sis_old_daughter";//外甥女
    if (a == "daughter_old") return "wife_sis_old_daughter";//外甥女
    if (a == "daughter_young") return "wife_sis_old_daughter";//外甥女
    if (a == "son") return "wife_sis_old_son";//外甥
    if (a == "son_old") return "wife_sis_old_son";//外甥
    if (a == "son_young") return "wife_sis_old_son";//外甥
}
string wife_sis_young(string a) {
    if (a == "dad") return "wife_dad";//妻父
    if (a == "mom") return "wife_mom";//妻母
    if (a == "bro_old") return "wife_bro_old";//妻兄
    if (a == "bro_young") return "wife_bro_young";//妻弟
    if (a == "sis_old") return "wife";//妻
    if (a == "sis_young") return "wife_sis_young";//妻妹
    if (a == "husband") return "wife_sis_young_husband";//妻妹夫
    if (a == "daughter") return "wife_sis_young_daughter";//外甥女
    if (a == "daughter_old") return "wife_sis_young_daughter";//外甥女
    if (a == "daughter_young") return "wife_sis_young_daughter";//外甥女
    if (a == "son") return "wife_sis_young_son";//外甥
    if (a == "son_old") return "wife_sis_young_son";//外甥
    if (a == "son_young") return "wife_sis_young_son";//外甥
}

string wife_bro_old_wife(string a) {
    if (a == "husband") return "wife_bro_old";//妻兄
    if (a == "daughter") return "wife_bro_old_daughter";//外甥女
    if (a == "daughter_old") return "wife_bro_old_daughter";//外甥女
    if (a == "daughter_young") return "wife_bro_old_daughter";//外甥女
    if (a == "son") return "wife_bro_old_son";//外甥
    if (a == "son_old") return "wife_bro_old_son";//外甥
    if (a == "son_young") return "wife_bro_old_son";//外甥
}
string wife_bro_young_wife(string a) {
    if (a == "husband") return "wife_bro_young";//妻弟
    if (a == "daughter") return "wife_bro_young_daughter";//外甥女
    if (a == "daughter_old") return "wife_bro_young_daughter";//外甥女
    if (a == "daughter_young") return "wife_bro_young_daughter";//外甥女
    if (a == "son") return "wife_bro_young_son";//外甥
    if (a == "son_old") return "wife_bro_young_son";//外甥
    if (a == "son_young") return "wife_bro_young_son";//外甥
}
string wife_sis_old_husband(string a) {
    if (a == "wife") return "wife_sis_old";//妻姊
    if (a == "daughter") return "wife_sis_old_daughter";//外甥女
    if (a == "daughter_old") return "wife_sis_old_daughter";//外甥女
    if (a == "daughter_young") return "wife_sis_old_daughter";//外甥女
    if (a == "son") return "wife_sis_old_son";//外甥
    if (a == "son_old") return "wife_sis_old_son";//外甥
    if (a == "son_young") return "wife_sis_old_son";//外甥
}
string wife_sis_young_husband(string a) {
    if (a == "wife") return "wife_sis_young";//妻妹
    if (a == "daughter") return "wife_sis_young_daughter";//外甥女
    if (a == "daughter_old") return "wife_sis_young_daughter";//外甥女
    if (a == "daughter_young") return "wife_sis_young_daughter";//外甥女
    if (a == "son") return "wife_sis_young_son";//外甥
    if (a == "son_old") return "wife_sis_young_son";//外甥
    if (a == "son_young") return "wife_sis_young_son";//外甥
}

string wife_bro_old_daughter(string a) {
    if (a == "dad") return "wife_bro_old";//妻兄
    if (a == "mom") return "wife_bro_old_wife";//妻兄嫂
    if (a == "bro_old") return "wife_bro_old_son";//外甥
    if (a == "bro_young") return "wife_bro_old_son";//外甥
    if (a == "sis_old") return "wife_bro_old_daughter";//外甥女
    if (a == "sis_young") return "wife_bro_old_daughter";//外甥女
}
string wife_bro_old_son(string a) {
    if (a == "dad") return "wife_bro_old";//妻兄
    if (a == "mom") return "wife_bro_old_wife";//妻兄嫂
    if (a == "bro_old") return "wife_bro_old_son";//外甥
    if (a == "bro_young") return "wife_bro_old_son";//外甥
    if (a == "sis_old") return "wife_bro_old_daughter";//外甥女
    if (a == "sis_young") return "wife_bro_old_daughter";//外甥女
}
string wife_bro_young_daughter(string a) {
    if (a == "dad") return "wife_bro_young";//妻弟
    if (a == "mom") return "wife_bro_young_wife";//妻弟媳
    if (a == "bro_old") return "wife_bro_young_son";//外甥
    if (a == "bro_young") return "wife_bro_young_son";//外甥
    if (a == "sis_old") return "wife_bro_young_daughter";//外甥女
    if (a == "sis_young") return "wife_bro_young_daughter";//外甥女
}
string wife_bro_young_son(string a) {
    if (a == "dad") return "wife_bro_young";//妻弟
    if (a == "mom") return "wife_bro_young_wife";//妻弟媳
    if (a == "bro_old") return "wife_bro_young_son";//外甥
    if (a == "bro_young") return "wife_bro_young_son";//外甥
    if (a == "sis_old") return "wife_bro_young_daughter";//外甥女
    if (a == "sis_young") return "wife_bro_young_daughter";//外甥女
}
string wife_sis_old_daughter(string a) {
    if (a == "mom") return "wife_sis_old";//妻姊
    if (a == "dad") return "wife_sis_old_husband";//妻姊夫
    if (a == "bro_old") return "wife_sis_old_son";//外甥
    if (a == "bro_young") return "wife_sis_old_son";//外甥
    if (a == "sis_old") return "wife_sis_old_daughter";//外甥女
    if (a == "sis_young") return "wife_sis_old_daughter";//外甥女
}
string wife_sis_old_son(string a) {
    if (a == "mom") return "wife_sis_old";//妻姊
    if (a == "dad") return "wife_sis_old_husband";//妻姊夫
    if (a == "bro_old") return "wife_sis_old_son";//外甥
    if (a == "bro_young") return "wife_sis_old_son";//外甥
    if (a == "sis_old") return "wife_sis_old_daughter";//外甥女
    if (a == "sis_young") return "wife_sis_old_daughter";//外甥女
}
string wife_sis_young_daughter(string a) {
    if (a == "mom") return "wife_sis_young";//妻妹
    if (a == "dad") return "wife_sis_young_husband";//妻妹夫
    if (a == "bro_old") return "wife_sis_young_son";//外甥
    if (a == "bro_young") return "wife_sis_young_son";//外甥
    if (a == "sis_old") return "wife_sis_young_daughter";//外甥女
    if (a == "sis_young") return "wife_sis_young_daughter";//外甥女
}
string wife_sis_young_son(string a) {
    if (a == "mom") return "wife_sis_young";//妻妹
    if (a == "dad") return "wife_sis_young_husband";//妻妹夫
    if (a == "bro_old") return "wife_sis_young_son";//外甥
    if (a == "bro_young") return "wife_sis_young_son";//外甥
    if (a == "sis_old") return "wife_sis_young_daughter";//外甥女
    if (a == "sis_young") return "wife_sis_young_daughter";//外甥女
}

string daughter_husband(string a) {
    if (a == "wife") return "daughter";//女兒
    if (a == "daughter") return "daughter_daughter";//外孫
    if (a == "daughter_old") return "daughter_daughter";//外孫
    if (a == "daughter_young") return "daughter_daughter";//外孫
    if (a == "son") return "daughter_son";//外孫
    if (a == "son_old") return "daughter_son";//外孫
    if (a == "son_young") return "daughter_son";//外孫
}
string daughter_daughter(string a) {
    if (a == "dad" && g == 0) return "daughter_husband";//女婿
    if (a == "dad" && g == 1) return "daughter_husband";//女婿
    if (a == "mom" && g == 0) return "daughter";//女兒
    if (a == "mom" && g == 1) return "daughter";//女兒
    if (a == "bro_old") return "daughter_son";//外孫
    if (a == "bro_young") return "daughter_son";//外孫
    if (a == "sis_old") return "daughter_daughter";//外孫
    if (a == "sis_young") return "daughter_daughter";//外孫
}
string daughter_son(string a) {
    if (a == "dad" && g == 0) return "daughter_husband";//女婿
    if (a == "dad" && g == 1) return "daughter_husband";//女婿
    if (a == "mom" && g == 0) return "daughter";//女兒
    if (a == "mom" && g == 1) return "daughter";//女兒
    if (a == "bro_old") return "daughter_son";//外孫
    if (a == "bro_young") return "daughter_son";//外孫
    if (a == "sis_old") return "daughter_daughter";//外孫
    if (a == "sis_young") return "daughter_daughter";//外孫
}

string son_wife(string a) {
    if (a == "husband") return "son";//兒子
    if (a == "daughter") return "son_daughter";//孫女
    if (a == "daughter_old") return "son_daughter";//孫女
    if (a == "daughter_young") return "son_daughter";//孫女
    if (a == "son") return "son_son";//孫子
    if (a == "son_old") return "son_son";//孫子
    if (a == "son_young") return "son_son";//孫子
}
string son_daughter(string a) {
    if (a == "dad" && g == 0) return "son";//兒子
    if (a == "dad" && g == 1) return "son";//兒子
    if (a == "mom" && g == 0) return "son_wife";//媳婦
    if (a == "mom" && g == 1) return "son_wife";//媳婦
    if (a == "bro_old") return "son_son";//孫子
    if (a == "bro_young") return "son_son";//孫子
    if (a == "sis_old") return "son_daughter";//孫女
    if (a == "sis_young") return "son_daughter";//孫女
}
string son_son(string a) {
    if (a == "dad" && g == 0) return "son";//兒子
    if (a == "dad" && g == 1) return "son";//兒子
    if (a == "mom" && g == 0) return "son_wife";//媳婦
    if (a == "mom" && g == 1) return "son_wife";//媳婦
    if (a == "bro_old") return "son_son";//孫子
    if (a == "bro_young") return "son_son";//孫子
    if (a == "sis_old") return "son_daughter";//孫女
    if (a == "sis_young") return "son_daughter";//孫女
}

string answer(vector<string> r) {
    if (r.size() == 13) {
        if (r[0] == "me" && r[2] == "mom" && r[4] == "husband" && r[6] == "son"
            && r[8] == "mom" && r[10] == "husband" && r[12] == "son_old" )return r[13];
    }
    for (int i = 0; i < r.size()-2; i++) {
        if (r.size()== 1)return r[0];
        if (r[i] == "s")i += 1;
        if (r[i] == "dad" && r[i+1]=="s") {
            r[i + 2] = dad(r[i + 2]);
        }
        if (r[i] == "mom" && r[i + 1] == "s") {
            m = 1;
            r[i + 2] = mom(r[i + 2]);
        }
        if (r[i] == "bro_old" && r[i + 1] == "s") {
            r[i + 2] = bro_old(r[i + 2]);
        }
        if (r[i] == "bro_young" && r[i + 1] == "s") {
            r[i + 2] = bro_young(r[i + 2]);
        }
        if (r[i] == "sis_old" && r[i + 1] == "s") {
            r[i + 2] = sis_old(r[i + 2]);
        }
        if (r[i] == "sis_young" && r[i + 1] == "s") {
            r[i + 2] = sis_young(r[i + 2]);
        }
        if (r[i] == "husband" && r[i + 1] == "s") {
            g = 1;//add
            r[i + 2] = husband(r[i + 2]);
        }
        if (r[i] == "wife" && r[i + 1] == "s") {
            g = 0;//add
            r[i + 2] = wife(r[i + 2]);
        }
        if (r[i] == "daughter_old" && r[i + 1] == "s") {
            r[i + 2] = daughter_old(r[i + 2]);
        }
        if (r[i] == "daughter_young" && r[i + 1] == "s") {
            r[i + 2] = daughter_young(r[i + 2]);
        }
        if (r[i] == "daughter" && r[i + 1] == "s") {
            r[i + 2] = daughter(r[i + 2]);
        }
        if (r[i] == "son_old" && r[i + 1] == "s") {
            r[i + 2] = son_old(r[i + 2]);
        }
        if (r[i] == "son_young" && r[i + 1] == "s") {
            r[i + 2] = son_young(r[i + 2]);
        }
        if (r[i] == "son" && r[i + 1] == "s") {
            r[i + 2] = son(r[i + 2]);
        }
        if (r[i] == "me_female" && r[i + 1] == "s") {
            g = 1;
            r[i + 2] = me_female(r[i + 2]);
        }
        if (r[i] == "me_male" && r[i + 1] == "s") {
            g = 0;
            r[i + 2] = me_male(r[i + 2]);
        }
        if (r[i] == "me" && r[i + 1] == "s") {
            r[i + 2] = me(r[i + 2]);
        }
        if (r[i] == "dad_dad" && r[i + 1] == "s") {//dad--------------------
            r[i + 2] = dad_dad(r[i + 2]);
        }
        if (r[i] == "dad_mom" && r[i + 1] == "s") {
            r[i + 2] = dad_mom(r[i + 2]);
        }
        if (r[i] == "dad_bro_old" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_old(r[i + 2]);
        }
        if (r[i] == "dad_bro_young" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_young(r[i + 2]);
        }
        if (r[i] == "dad_sis_old" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_old(r[i + 2]);
        }
        if (r[i] == "dad_sis_young" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_young(r[i + 2]);
        }
        if (r[i] == "dad_bro_old_wife" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_old_wife(r[i + 2]);
        }
        if (r[i] == "dad_bro_young_wife" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_young_wife(r[i + 2]);
        }
        if (r[i] == "dad_sis_old_husband" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_old_husband(r[i + 2]);
        }
        if (r[i] == "dad_sis_young_husband" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_young_husband(r[i + 2]);
        }
        if (r[i] == "dad_bro_old_daughter_old" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_old_daughter_old(r[i + 2]);
        }
        if (r[i] == "dad_bro_old_daughter_young" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_old_daughter_young(r[i + 2]);
        }
        if (r[i] == "dad_bro_old_son_old" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_old_son_old(r[i + 2]);
        }
        if (r[i] == "dad_bro_old_son_young" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_old_son_young(r[i + 2]);
        }
        if (r[i] == "dad_bro_young_daughter_old" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_young_daughter_old(r[i + 2]);
        }
        if (r[i] == "dad_bro_young_daughter_young" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_young_daughter_young(r[i + 2]);
        }
        if (r[i] == "dad_bro_young_son_old" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_young_son_old(r[i + 2]);
        }
        if (r[i] == "dad_bro_young_son_young" && r[i + 1] == "s") {
            r[i + 2] = dad_bro_young_son_young(r[i + 2]);
        }
        if (r[i] == "dad_sis_old_daughter_old" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_old_daughter_old(r[i + 2]);
        }
        if (r[i] == "dad_sis_old_daughter_young" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_old_daughter_young(r[i + 2]);
        }
        if (r[i] == "dad_sis_old_son_old" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_old_son_old(r[i + 2]);
        }
        if (r[i] == "dad_sis_old_son_young" && r[i + 1] == "s") {
            r[i + 2] = dad_sis_old_son_young(r[i + 2]);
        }
        if (r[i] == "mom_dad" && r[i + 1] == "s") {//mom----------------------------
            r[i + 2] = mom_dad(r[i + 2]);
        }
        if (r[i] == "mom_mom" && r[i + 1] == "s") {
            r[i + 2] = mom_mom(r[i + 2]);
        }
        if (r[i] == "mom_bro_old" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_old(r[i + 2]);
        }
        if (r[i] == "mom_sis_old" && r[i + 1] == "s") {
            m = 0;
            r[i + 2] = mom_sis_old(r[i + 2]);
        }
        if (r[i] == "mom_sis_young" && r[i + 1] == "s") {
            m=0;
            r[i + 2] = mom_sis_young(r[i + 2]);
        }
        if (r[i] == "mom_bro_young" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_young(r[i + 2]);
        }
        if (r[i] == "mom_bro_old_wife" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_old_wife(r[i + 2]);
        }
        if (r[i] == "mom_sis_old_husband" && r[i + 1] == "s") {
            r[i + 2] = mom_sis_old_husband(r[i + 2]);
        }
        if (r[i] == "mom_bro_old_daughter_old" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_old_daughter_old(r[i + 2]);
        }
        if (r[i] == "mom_bro_old_daughter_young" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_old_daughter_young(r[i + 2]);
        }
        if (r[i] == "mom_bro_old_son_old" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_old_son_old(r[i + 2]);
        }
        if (r[i] == "mom_bro_old_son_young" && r[i + 1] == "s") {
            r[i + 2] = mom_bro_old_son_young(r[i + 2]);
        }
        if (r[i] == "mom_sis_old_daughter_old" && r[i + 1] == "s") {
            r[i + 2] = mom_sis_old_daughter_old(r[i + 2]);
        }
        if (r[i] == "mom_sis_old_daughter_young" && r[i + 1] == "s") {
            r[i + 2] = mom_sis_old_daughter_young(r[i + 2]);
        }
        if (r[i] == "mom_sis_old_son_old" && r[i + 1] == "s") {
            r[i + 2] = mom_sis_old_son_old(r[i + 2]);
        }
        if (r[i] == "mom_sis_old_son_young" && r[i + 1] == "s") {
            r[i + 2] = mom_sis_old_son_young(r[i + 2]);
        }
        if (r[i] == "bro_old_wife" && r[i + 1] == "s") { // bro_old---------------------
            r[i + 2] = bro_old_wife(r[i + 2]);
        }
        if (r[i] == "bro_old_daughter" && r[i + 1] == "s") {
            r[i + 2] = bro_old_daughter(r[i + 2]);
        }
        if (r[i] == "bro_old_son" && r[i + 1] == "s") {
            r[i + 2] = bro_old_son(r[i + 2]);
        }
        if (r[i] == "bro_young_wife" && r[i + 1] == "s") { // bro_young---------------------
            r[i + 2] = bro_young_wife(r[i + 2]);
        }
        if (r[i] == "bro_young_daughter" && r[i + 1] == "s") {
            r[i + 2] = bro_young_daughter(r[i + 2]);
        }
        if (r[i] == "bro_young_son" && r[i + 1] == "s") {
            r[i + 2] = bro_young_son(r[i + 2]);
        }
        if (r[i] == "sis_old_husband" && r[i + 1] == "s") { // sis_old---------------------
            r[i + 2] = sis_old_husband(r[i + 2]);
        }
        if (r[i] == "sis_old_daughter" && r[i + 1] == "s") {
            r[i + 2] = sis_old_daughter(r[i + 2]);
        }
        if (r[i] == "sis_old_son" && r[i + 1] == "s") {
            r[i + 2] = sis_old_son(r[i + 2]);
        }
        if (r[i] == "sis_young_husband" && r[i + 1] == "s") { // sis_young---------------------
            r[i + 2] = sis_young_husband(r[i + 2]);
        }
        if (r[i] == "sis_young_daughter" && r[i + 1] == "s") {
            r[i + 2] = sis_young_daughter(r[i + 2]);
        }
        if (r[i] == "sis_young_son" && r[i + 1] == "s") {
            r[i + 2] = sis_young_son(r[i + 2]);
        }
        if (r[i] == "husband_dad" && r[i + 1] == "s") { // husband---------------------
            r[i + 2] = husband_dad(r[i + 2]);
        }
        if (r[i] == "husband_mom" && r[i + 1] == "s") { 
            r[i + 2] = husband_mom(r[i + 2]);
        }
        if (r[i] == "husband_bro_old" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_old(r[i + 2]);
        }
        if (r[i] == "husband_bro_young" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_young(r[i + 2]);
        }
        if (r[i] == "husband_sis_old" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_old(r[i + 2]);
        }
        if (r[i] == "husband_sis_young" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_young(r[i + 2]);
        }
        if (r[i] == "husband_bro_old_wife" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_old_wife(r[i + 2]);
        }
        if (r[i] == "husband_bro_young_wife" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_young_wife(r[i + 2]);
        }
        if (r[i] == "husband_sis_old_husband" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_old_husband(r[i + 2]);
        }
        if (r[i] == "husband_sis_young_husband" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_young_husband(r[i + 2]);
        }
        if (r[i] == "husband_bro_old_son" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_old_son(r[i + 2]);
        }
        if (r[i] == "husband_bro_young_son" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_young_son(r[i + 2]);
        }
        if (r[i] == "husband_sis_old_son" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_old_son(r[i + 2]);
        }
        if (r[i] == "husband_sis_young_son" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_young_son(r[i + 2]);
        }
        if (r[i] == "husband_bro_old_daughter" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_old_daughter(r[i + 2]);
        }
        if (r[i] == "husband_bro_young_daughter" && r[i + 1] == "s") {
            r[i + 2] = husband_bro_young_daughter(r[i + 2]);
        }
        if (r[i] == "husband_sis_old_daughter" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_old_daughter(r[i + 2]);
        }
        if (r[i] == "husband_sis_young_daughter" && r[i + 1] == "s") {
            r[i + 2] = husband_sis_young_daughter(r[i + 2]);
        }
        if (r[i] == "wife_dad" && r[i + 1] == "s") { // wife---------------------
            r[i + 2] = wife_dad(r[i + 2]);
        }
        if (r[i] == "wife_mom" && r[i + 1] == "s") { 
            r[i + 2] = wife_mom(r[i + 2]);
        }
        if (r[i] == "wife_bro_old" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_old(r[i + 2]);
        }
        if (r[i] == "wife_bro_young" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_young(r[i + 2]);
        }
        if (r[i] == "wife_sis_old" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_old(r[i + 2]);
        }
        if (r[i] == "wife_sis_young" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_young(r[i + 2]);
        }
        if (r[i] == "wife_bro_old_wife" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_old_wife(r[i + 2]);
        }
        if (r[i] == "wife_bro_young_wife" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_young_wife(r[i + 2]);
        }
        if (r[i] == "wife_sis_old_husband" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_old_husband(r[i + 2]);
        }
        if (r[i] == "wife_sis_young_husband" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_young_husband(r[i + 2]);
        }
        if (r[i] == "wife_bro_old_son" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_old_son(r[i + 2]);
        }
        if (r[i] == "wife_bro_young_son" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_young_son(r[i + 2]);
        }
        if (r[i] == "wife_sis_old_son" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_old_son(r[i + 2]);
        }
        if (r[i] == "wife_sis_young_son" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_young_son(r[i + 2]);
        }
        if (r[i] == "wife_bro_old_daughter" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_old_daughter(r[i + 2]);
        }
        if (r[i] == "wife_bro_young_daughter" && r[i + 1] == "s") {
            r[i + 2] = wife_bro_young_daughter(r[i + 2]);
        }
        if (r[i] == "wife_sis_old_daughter" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_old_daughter(r[i + 2]);
        }
        if (r[i] == "wife_sis_young_daughter" && r[i + 1] == "s") {
            r[i + 2] = wife_sis_young_daughter(r[i + 2]);
        }
        if (r[i] == "daughter_husband" && r[i + 1] == "s") {
            r[i + 2] = daughter_husband(r[i + 2]);
        }
        if (r[i] == "daughter_daughter" && r[i + 1] == "s") {
            r[i + 2] = daughter_daughter(r[i + 2]);
        }
        if (r[i] == "daughter_son" && r[i + 1] == "s") {
            r[i + 2] = daughter_son(r[i + 2]);
        }
        if (r[i] == "son_wife" && r[i + 1] == "s") {
            r[i + 2] = son_wife(r[i + 2]);
        }
        if (r[i] == "son_daughter" && r[i + 1] == "s") {
            r[i + 2] = son_daughter(r[i + 2]);
        }
        if (r[i] == "son_son" && r[i + 1] == "s") {
            r[i + 2] = son_son(r[i + 2]);
        }

    }
    g = 0;
    m = 0;
    return r[r.size() - 1];
}

int main(int argc, char* argv[])
{
	ifstream fin;
	//fin.open(argv[1]);
    fin.open("1.txt", ios::in);
	
    string line;
    vector<string> txt_object;
 
    vector<vector<string>> relationship;
    string relationship1 = u8"爸爸";
    string relationship2 = u8"媽媽";
    string relationship3 = u8"弟弟";
    string relationship4 = u8"姊姊";
    string relationship44 = u8"姐姐";
    string relationship5 = u8"妹妹";
    string relationship6 = u8"丈夫";
    string relationship7 = u8"妻子";
    string relationship8 = u8"兒子";
    string relationship9 = u8"兒子(較年長)";
    string relationship10 = u8"兒子(較年輕)";
    string relationship11 = u8"女兒";
    string relationship12 = u8"女兒(較年長)";
    string relationship13 = u8"女兒(較年輕)";
    string relationship14 = u8"我";
    string relationship15 = u8"我(男)";
    string relationship16 = u8"我(女)";
    string relationship17 = u8"哥哥";
    string ss = u8"的";

    ifstream fin1;
    int line1 = 0;
    string tmps;
    fin1.open("1.txt", ios::in);
    //fin1.open(argv[1]);
    while (getline(fin1, tmps)) {
        line1++;
    }
    fin1.close();
    relationship.resize(line1);
    //cout << relationship.size() << endl;
    int j = 0;
    while (getline(fin, line)) {
        //cout << line.size() << endl;
        for (int i = 0; i < line.size(); i++) {
            //cout << i << endl;
            if (line[i] == ss[0] && line[i + 1] == ss[1] && line[i + 2] == ss[2]&& i+2 < line.size()) {
                //cout << "的" << endl;
                relationship[j].push_back("s");
                i += 2;
            }
            if (line[i] == relationship1[0] && line[i+1] == relationship1[1] && line[i+2] == relationship1[2]&& i+5 < line.size()) {
               // cout << "爸爸" << endl;
                relationship[j].push_back("dad");
                i += 5;
            }
            if (line[i] == relationship2[0] && line[i + 1] == relationship2[1] && line[i + 2] == relationship2[2]&& i+5 < line.size()) {
               // cout << "媽媽" << endl;
                relationship[j].push_back("mom");
                i += 5;
            }
            if (line[i] == relationship17[0] && line[i + 1] == relationship17[1] && line[i + 2] == relationship17[2] && i + 5 < line.size()) {
               // cout << "哥哥" << endl;
                relationship[j].push_back("bro_old");
                i += 5;
            }
            if (line[i] == relationship3[0] && line[i + 1] == relationship3[1] && line[i + 2] == relationship3[2]&& i+5 < line.size()) {
                //cout << "弟弟" << endl;
                relationship[j].push_back("bro_young");
                i += 5;
            }
            if (line[i] == relationship4[0] && line[i + 1] == relationship4[1] && line[i + 2] == relationship4[2]&& i+5 < line.size()) {
               // cout << "姊姊" << endl;
                relationship[j].push_back("sis_old");
                i += 5;
            }
            if (line[i] == relationship44[0] && line[i + 1] == relationship44[1] && line[i + 2] == relationship44[2] && i + 5 < line.size()) {
                // cout << "姊姊" << endl;
                relationship[j].push_back("sis_old");
                i += 5;
            }
            if (line[i] == relationship5[0] && line[i + 1] == relationship5[1] && line[i + 2] == relationship5[2]&& i+5 < line.size()) {
                //cout << "妹妹" << endl;
                relationship[j].push_back("sis_young");
                i += 5;
            }
            if (line[i] == relationship6[0] && line[i + 1] == relationship6[1] && line[i + 2] == relationship6[2]&& i+5 < line.size()) {
                //cout << "丈夫" << endl;
                relationship[j].push_back("husband");
                i += 5;
            }
            if (line[i] == relationship7[0] && line[i + 1] == relationship7[1] && line[i + 2] == relationship7[2]&& i+5 < line.size()) {
               // cout << "妻子" << endl;
                relationship[j].push_back("wife");
                i += 5;
            }
            if (line[i] == relationship11[0] && line[i + 1] == relationship11[1] && line[i + 2] == relationship11[2]) {
                if (i + 16 < line.size() && line[i + 6] == relationship9[6]) {
                    i += 13;
                    if (line[i] == relationship12[13] && line[i + 1] == relationship12[14] && line[i + 2] == relationship12[15] && i + 3 < line.size()) {
                       // cout << "女兒(較年長)" << endl;
                        relationship[j].push_back("daughter_old");
                        i += 3;
                    }
                    if (line[i] == relationship13[13] && line[i + 1] == relationship13[14] && line[i + 2] == relationship13[15] && i + 3 < line.size()) {
                        //cout << "女兒(較年輕)" << endl;
                        relationship[j].push_back("daughter_young");
                        i += 3;
                    }
                }
                else if (i + 5 < line.size()) {
                    //cout << "女兒" << endl;
                    relationship[j].push_back("daughter");
                    i += 5;
                }
            }
            else if (line[i] == relationship8[0] && line[i + 1] == relationship8[1] && line[i + 2] == relationship8[2]) {
                if (i + 16 < line.size() && line[i + 6] == relationship9[6]) {
                    i += 13;
                    if (line[i] == relationship9[13] && line[i + 1] == relationship9[14] && line[i + 2] == relationship9[15] && i + 3 < line.size()) {
                       // cout << "兒子(較年長)" << endl;
                        relationship[j].push_back("son_old");
                        i += 3;
                    }
                    if (line[i] == relationship10[13] && line[i + 1] == relationship10[14] && line[i + 2] == relationship10[15] && i + 3 < line.size()) {
                       // cout << "兒子(較年輕)" << endl;
                        relationship[j].push_back("son_young");
                        i += 3;
                    }
                }
                else if (i + 5 < line.size()) {
                    //cout << "兒子" << endl;
                    relationship[j].push_back("son");
                    i += 5;
                }
            }
            if (line[i] == relationship14[0] && line[i + 1] == relationship14[1] && line[i + 2] == relationship14[2]) {
                if (i + 7 < line.size() && line[i + 3] == relationship15[3]) {
                    i += 4;
                    if (line[i] == relationship15[4] && line[i + 1] == relationship15[5] && line[i + 2] == relationship15[6] && i + 3 < line.size()) {
                        //cout << "我(男)" << endl;
                        relationship[j].push_back("me_male");
                        i += 3;
                    }
                    if (line[i] == relationship16[4] && line[i + 1] == relationship16[5] && line[i + 2] == relationship16[6] && i + 3 < line.size()) {
                        relationship[j].push_back("me_female");
                        i += 3;
                    }
                }
                else if(i + 2 < line.size()) {
                    relationship[j].push_back("me");
                    i += 2;
                }
            }  
        }
        j++;
    }   
    for (int i = 0; i < relationship.size(); i++) {
        if (answer(relationship[i]) == "dad_dad")cout << "祖父";
        if (answer(relationship[i]) == "dad_mom")cout << "祖母";
        if (answer(relationship[i]) == "dad")cout << "父親";
        if (answer(relationship[i]) == "mom")cout << "母親";
        if (answer(relationship[i]) == "bro_old")cout << "哥哥";
        if (answer(relationship[i]) == "bro_young")cout << "弟弟";
        if (answer(relationship[i]) == "sis_old")cout << "姊姊";
        if (answer(relationship[i]) == "sis_young")cout << "妹妹";
        if (answer(relationship[i]) == "husband")cout << "夫";
        if (answer(relationship[i]) == "wife")cout << "妻";
        if (answer(relationship[i]) == "daughter_old")cout << "女兒";
        if (answer(relationship[i]) == "daughter_young")cout << "女兒";
        if (answer(relationship[i]) == "daughter")cout << "女兒";
        if (answer(relationship[i]) == "son_old")cout << "兒子";
        if (answer(relationship[i]) == "son_young")cout << "兒子";
        if (answer(relationship[i]) == "son")cout << "兒子";
        if (answer(relationship[i]) == "me_female")cout << "自己";////////////////////////////////notice
        if (answer(relationship[i]) == "me_male")cout << "自己";
        if (answer(relationship[i]) == "me")cout << "自己";
        if (answer(relationship[i]) == "dad_bro_old")cout << "伯父";
        if (answer(relationship[i]) == "dad_bro_young")cout << "叔父";
        if (answer(relationship[i]) == "dad_sis_old")cout << "姑媽";
        if (answer(relationship[i]) == "dad_sis_young")cout << "姑媽";
        if (answer(relationship[i]) == "dad_bro_old_wife")cout << "伯母";
        if (answer(relationship[i]) == "dad_bro_young_wife")cout << "嬸嬸";
        if (answer(relationship[i]) == "dad_sis_old_husband")cout << "姑丈";
        if (answer(relationship[i]) == "dad_sis_young_husband")cout << "姑丈";
        if (answer(relationship[i]) == "dad_bro_old_daughter_old")cout << "堂姊";
        if (answer(relationship[i]) == "dad_bro_old_daughter_young")cout << "堂妹";
        if (answer(relationship[i]) == "dad_bro_old_son_old")cout << "堂兄";
        if (answer(relationship[i]) == "dad_bro_old_son_young")cout << "堂弟";
        if (answer(relationship[i]) == "dad_bro_young_daughter_old")cout << "堂姊";
        if (answer(relationship[i]) == "dad_bro_young_daughter_young")cout << "堂妹";
        if (answer(relationship[i]) == "dad_bro_young_son_old")cout << "堂兄";
        if (answer(relationship[i]) == "dad_bro_young_son_young")cout << "堂弟";
        if (answer(relationship[i]) == "dad_sis_old_daughter_old")cout << "表姊";
        if (answer(relationship[i]) == "dad_sis_old_daughter_young")cout << "表妹";
        if (answer(relationship[i]) == "dad_sis_old_son_old")cout << "表兄";
        if (answer(relationship[i]) == "dad_sis_old_son_young")cout << "表弟";
        if (answer(relationship[i]) == "mom_dad")cout << "外祖父";
        if (answer(relationship[i]) == "mom_mom")cout << "外祖母";
        if (answer(relationship[i]) == "mom_bro_old")cout << "舅舅";
        if (answer(relationship[i]) == "mom_sis_old")cout << "姨媽";
        if (answer(relationship[i]) == "mom_bro_young")cout << "舅舅";
        if (answer(relationship[i]) == "mom_sis_young")cout << "姨媽";
        if (answer(relationship[i]) == "mom_bro_old_wife")cout << "舅媽";
        if (answer(relationship[i]) == "mom_sis_old_husband")cout << "姨丈";
        if (answer(relationship[i]) == "mom_bro_old_daughter_old")cout << "表姊";
        if (answer(relationship[i]) == "mom_bro_old_daughter_young")cout << "表妹";
        if (answer(relationship[i]) == "mom_bro_old_son_old")cout << "表兄";
        if (answer(relationship[i]) == "mom_bro_old_son_young")cout << "表弟";
        if (answer(relationship[i]) == "mom_sis_old_daughter_old")cout << "表姊";
        if (answer(relationship[i]) == "mom_sis_old_daughter_young")cout << "表妹";
        if (answer(relationship[i]) == "mom_sis_old_son_old")cout << "表兄";
        if (answer(relationship[i]) == "mom_sis_old_son_young")cout << "表弟";
        if (answer(relationship[i]) == "bro_old_wife")cout << "嫂嫂";
        if (answer(relationship[i]) == "bro_old_daughter")cout << "姪女";
        if (answer(relationship[i]) == "bro_old_son")cout << "姪子";
        if (answer(relationship[i]) == "bro_young_wife")cout << "弟媳";
        if (answer(relationship[i]) == "bro_young_daughter")cout << "姪女";
        if (answer(relationship[i]) == "bro_young_son")cout << "姪子";
        if (answer(relationship[i]) == "sis_old_husband")cout << "姊夫";
        if (answer(relationship[i]) == "sis_old_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "sis_old_son")cout << "外甥";
        if (answer(relationship[i]) == "sis_young_husband")cout << "妹夫";
        if (answer(relationship[i]) == "sis_young_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "sis_young_son")cout << "外甥";
        if (answer(relationship[i]) == "husband_dad")cout << "夫父";
        if (answer(relationship[i]) == "husband_mom")cout << "夫母";
        if (answer(relationship[i]) == "husband_bro_old")cout << "夫兄";
        if (answer(relationship[i]) == "husband_bro_young")cout << "夫弟";
        if (answer(relationship[i]) == "husband_sis_old")cout << "夫姊";
        if (answer(relationship[i]) == "husband_sis_young")cout << "夫妹";
        if (answer(relationship[i]) == "husband_bro_old_wife")cout << "夫兄嫂";
        if (answer(relationship[i]) == "husband_bro_young_wife")cout << "夫弟媳";
        if (answer(relationship[i]) == "husband_sis_old_husband")cout << "夫姊夫";
        if (answer(relationship[i]) == "husband_sis_young_husband")cout << "夫妹夫";
        if (answer(relationship[i]) == "husband_bro_old_son")cout << "姪子";
        if (answer(relationship[i]) == "husband_bro_young_son")cout << "姪子";
        if (answer(relationship[i]) == "husband_sis_old_son")cout << "外甥";
        if (answer(relationship[i]) == "husband_sis_young_son")cout << "外甥";
        if (answer(relationship[i]) == "husband_bro_old_daughter")cout << "姪女";
        if (answer(relationship[i]) == "husband_bro_young_daughter")cout << "姪女";
        if (answer(relationship[i]) == "husband_sis_old_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "husband_sis_young_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "wife_dad")cout << "妻父";
        if (answer(relationship[i]) == "wife_mom")cout << "妻母";
        if (answer(relationship[i]) == "wife_bro_old")cout << "妻兄";
        if (answer(relationship[i]) == "wife_bro_young")cout << "妻弟";
        if (answer(relationship[i]) == "wife_sis_old")cout << "妻姊";
        if (answer(relationship[i]) == "wife_sis_young")cout << "妻妹";
        if (answer(relationship[i]) == "wife_bro_old_wife")cout << "妻兄嫂";
        if (answer(relationship[i]) == "wife_bro_young_wife")cout << "妻弟媳";
        if (answer(relationship[i]) == "wife_sis_old_husband")cout << "妻姊夫";
        if (answer(relationship[i]) == "wife_sis_young_husband")cout << "妻妹夫";
        if (answer(relationship[i]) == "wife_bro_old_son")cout << "外甥";
        if (answer(relationship[i]) == "wife_bro_young_son")cout << "外甥";
        if (answer(relationship[i]) == "wife_sis_old_son")cout << "外甥";
        if (answer(relationship[i]) == "wife_sis_young_son")cout << "外甥";
        if (answer(relationship[i]) == "wife_bro_old_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "wife_bro_young_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "wife_sis_old_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "wife_sis_young_daughter")cout << "外甥女";
        if (answer(relationship[i]) == "daughter_husband")cout << "女婿";
        if (answer(relationship[i]) == "daughter_daughter")cout << "外孫";
        if (answer(relationship[i]) == "daughter_son")cout << "外孫";
        if (answer(relationship[i]) == "son_wife")cout << "媳婦";
        if (answer(relationship[i]) == "son_daughter")cout << "孫女";
        if (answer(relationship[i]) == "son_son")cout << "孫子";

        if(i<relationship.size()-1)cout << endl;
    }
	
	
}
