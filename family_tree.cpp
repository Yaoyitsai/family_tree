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
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "bro_old") return "dad_bro_old";//�B��
    if (a == "bro_young") return "dad_bro_young";//����
    if (a == "sis_old") return "dad_sis_old";//�h��
    if (a == "sis_young") return "dad_sis_young";//�h��
    if (a == "wife") return "mom";//����
    if (a == "daughter" && g == 0) return "sis_old";//�ۤv(�w�]) ���令�j�j
    if (a == "daughter" && g == 1) return "me_female";//�ۤv(�w�]) 
    if (a == "daughter_old") return "sis_old";//�n�n
    if (a == "daughter_young") return "sis_young";//�f�f
    if (a == "son" && g == 0) return "bro_old";//�ۤv(�w�])
    if (a == "son" && g == 1) return "bro_old";//�ۤv(�w�]) ���令����
    if (a == "son_old") return "bro_old";//����
    if (a == "son_young") return "bro_young";//�̧�
}

string mom(string a) { 
    if (a == "dad") return "mom_dad";//�~����
    if (a == "mom") return "mom_mom";//�~����
    if (a == "bro_old") return "mom_bro_old";//����
    if (a == "bro_young") return "mom_bro_old";//����
    if (a == "sis_old") return "mom_sis_old";//����
    if (a == "sis_young") return "mom_sis_young";//����
    if (a == "husband") return "dad";//����
    if (a == "daughter" && g == 0) return "sis_old";//�ۤv(�w�]) ���令�j�j
    if (a == "daughter" && g == 1) return "me_female";//�ۤv(�w�]) 
    if (a == "daughter_old") return "sis_old";//�n�n
    if (a == "daughter_young") return "sis_young";//�f�f
    if (a == "son" && g == 0) return "bro_old";//�ۤv(�w�])
    if (a == "son" && g == 1) return "bro_old";//�ۤv(�w�]) ���令����
    if (a == "son_old") return "bro_old";//����
    if (a == "son_young") return "bro_young";//�̧�
}

string bro_old(string a) { 
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "bro_old";//
    if (a == "bro_young") return "me";//
    if (a == "sis_old") return "sis_old";//
    if (a == "sis_young") return "sis_young";//
    if (a == "wife") return "bro_old_wife";//�A�A
    if (a == "daughter") return "bro_old_daughter";//���k
    if (a == "daughter_old") return "bro_old_daughter";//���k
    if (a == "daughter_young") return "bro_old_daughter";//���k
    if (a == "son") return "bro_old_son";//���l
    if (a == "son_old") return "bro_old_son";//���l
    if (a == "son_young") return "bro_old_son";//���l
}

string bro_young(string a) {
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "me";//
    if (a == "bro_young") return "bro_young";//
    if (a == "sis_old") return "sis_old";//
    if (a == "sis_young") return "sis_young";//
    if (a == "wife") return "bro_young_wife";//�̷@
    if (a == "daughter") return "bro_young_daughter";//���k
    if (a == "daughter_old") return "bro_young_daughter";//���k
    if (a == "daughter_young") return "bro_young_daughter";//���k
    if (a == "son") return "bro_young_son";//���l
    if (a == "son_old") return "bro_young_son";//���l
    if (a == "son_young") return "bro_young_son";//���l
}

string sis_old(string a) {
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "bro_old";//
    if (a == "bro_young") return "me";//
    if (a == "sis_old") return "sis_old";//
    if (a == "sis_young") return "me";//
    if (a == "husband") return "sis_old_husband";//�n��
    if (a == "daughter") return "sis_old_daughter";//�~�c�k
    if (a == "daughter_old") return "sis_old_daughter";//�~�c�k
    if (a == "daughter_young") return "sis_old_daughter";//�~�c�k
    if (a == "son") return "sis_old_son";//�~�c
    if (a == "son_old") return "sis_old_son";//�~�c
    if (a == "son_young") return "sis_old_son";//�~�c
}

string sis_young(string a) {
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "me";//
    if (a == "bro_young") return "me";//
    if (a == "sis_old") return "me";//
    if (a == "sis_young") return "sis_young";//
    if (a == "husband") return "sis_young_husband";//�f��
    if (a == "daughter") return "sis_young_daughter";//�~�c�k
    if (a == "daughter_old") return "sis_young_daughter";//�~�c�k
    if (a == "daughter_young") return "sis_young_daughter";//�~�c�k
    if (a == "son") return "sis_young_son";//�~�c
    if (a == "son_old") return "sis_young_son";//�~�c
    if (a == "son_young") return "sis_young_son";//�~�c
}

string husband(string a) {
    if (a == "dad") return "husband_dad";//�Ҥ�
    if (a == "mom") return "husband_mom";//�ҥ�
    if (a == "bro_old") return "husband_bro_old";//�ҥS
    if (a == "bro_young") return "husband_bro_young";//�ҧ�
    if (a == "sis_old") return "husband_sis_old";//�ҩn
    if (a == "sis_young") return "husband_sis_young";//�ҩf
    if (a == "wife") return "me_female";//��(�k)
    if (a == "daughter") return "daughter";//�k��
    if (a == "daughter_old") return "daughter";//�k��
    if (a == "daughter_young") return "daughter";//�k��
    if (a == "son") return "son";//��l
    if (a == "son_old") return "son";//��l
    if (a == "son_young") return "son";//��l
}

string wife(string a) {
    if (a == "dad") return "wife_dad";//�d��
    if (a == "mom") return "wife_mom";//�d��
    if (a == "bro_old") return "wife_bro_old";//�d�S
    if (a == "bro_young") return "wife_bro_young";//�d��
    if (a == "sis_old") return "wife_sis_old";//�d�n
    if (a == "sis_young") return "wife_sis_young";//�d�f
    if (a == "husband") return "me_male";//��(�k)
    //if (a == "wife") { g = 0; return "wife"; }// �ڪ��k�઺����(�w�]�|�ܦ��d�l)
    if (a == "daughter") return "daughter";//�k��
    if (a == "daughter_old") return "daughter";//�k��
    if (a == "daughter_young") return "daughter";//�k��
    if (a == "son") return "son";//�~�]
    if (a == "son_old") return "son";//�~�]
    if (a == "son_young") return "son";//�~�]
}

string daughter_old(string a) {
    if (a == "dad" && g == 0) return "me_male";//��(�k)
    if (a == "dad" && g == 1) return "husband";//��
    if (a == "mom" && g == 0) return "wife";//�d
    if (a == "mom" && g == 1) return "me_female";//��(�k)
    if (a == "bro_old") return "son";//��l
    if (a == "bro_young") return "son";//��l
    if (a == "sis_old") return "daughter";//�k��
    if (a == "sis_young") return "daughter";//�k��
    if (a == "husband") return "daughter_husband";//�k�B
    if (a == "daughter") return "daughter_daughter";//�~�]
    if (a == "daughter_old") return "daughter_daughter";//�~�]
    if (a == "daughter_young") return "daughter_daughter";//�~�]
    if (a == "son") return "daughter_son";//�~�]
    if (a == "son_old") return "daughter_son";//�~�]
    if (a == "son_young") return "daughter_son";//�~�]
}

string daughter_young(string a) {
    if (a == "dad" && g == 0) return "me_male";//��(�k)
    if (a == "dad" && g == 1) return "husband";//��
    if (a == "mom" && g == 0) return "wife";//�d
    if (a == "mom" && g == 1) return "me_female";//��(�k)
    if (a == "bro_old") return "son";//��l
    if (a == "bro_young") return "son";//��l
    if (a == "sis_old") return "daughter";//�k��
    if (a == "sis_young") return "daughter";//�k��
    if (a == "husband") return "daughter_husband";//�k�B
    if (a == "daughter") return "daughter_daughter";//�~�]
    if (a == "daughter_old") return "daughter_daughter";//�~�]
    if (a == "daughter_young") return "daughter_daughter";//�~�]
    if (a == "son") return "daughter_son";//�~�]
    if (a == "son_old") return "daughter_son";//�~�]
    if (a == "son_young") return "daughter_son";//�~�]
}

string daughter(string a) {
    if (a == "dad" && g == 0) return "me_male";//��(�k)
    if (a == "dad" && g == 1) return "husband";//��
    if (a == "mom" && g == 0) return "wife";//�d
    if (a == "mom" && g == 1) return "me_female";//��(�k)
    if (a == "bro_old") return "son";//��l
    if (a == "bro_young") return "son";//��l
    if (a == "sis_old") return "daughter";//�k��
    if (a == "sis_young") return "daughter";//�k��
    if (a == "husband") return "daughter_husband";//�k�B
    if (a == "daughter") return "daughter_daughter";//�~�]
    if (a == "daughter_old") return "daughter_daughter";//�~�]
    if (a == "daughter_young") return "daughter_daughter";//�~�]
    if (a == "son") return "daughter_son";//�~�]
    if (a == "son_old") return "daughter_son";//�~�]
    if (a == "son_young") return "daughter_son";//�~�]
}

string son_old(string a) {
    if (a == "dad" && g == 0) return "me_male";//��(�k)
    if (a == "dad" && g == 1) return "husband";//��
    if (a == "mom" && g == 0) return "wife";//�d
    if (a == "mom" && g == 1) return "me_female";//��(�k)
    if (a == "bro_old") return "son";//��l
    if (a == "bro_young") return "son";//��l
    if (a == "sis_old") return "daughter";//�k��
    if (a == "sis_young") return "daughter";//�k��
    if (a == "wife") return "son_wife";//�@��
    if (a == "daughter") return "son_daughter";//�]�k
    if (a == "daughter_old") return "son_daughter";//�]�k
    if (a == "daughter_young") return "son_daughter";//�]�k
    if (a == "son") return "son_son";//�]�l
    if (a == "son_old") return "son_son";//�]�l
    if (a == "son_young") return "son_son";//�]�l
}

string son_young(string a) {
    if (a == "dad" && g == 0) return "me_male";//��(�k)
    if (a == "dad" && g == 1) return "husband";//��
    if (a == "mom" && g == 0) return "wife";//�d
    if (a == "mom" && g == 1) return "me_female";//��(�k)
    if (a == "bro_old") return "son";//��l
    if (a == "bro_young") return "son";//��l
    if (a == "sis_old") return "daughter";//�k��
    if (a == "sis_young") return "daughter";//�k��
    if (a == "wife") return "son_wife";//�@��
    if (a == "daughter") return "son_daughter";//�]�k
    if (a == "daughter_old") return "son_daughter";//�]�k
    if (a == "daughter_young") return "son_daughter";//�]�k
    if (a == "son") return "son_son";//�]�l
    if (a == "son_old") return "son_son";//�]�l
    if (a == "son_young") return "son_son";//�]�l
}

string son(string a) {
    if (a == "dad" && g == 0) return "me_male";//��(�k)
    if (a == "dad" && g == 1) return "husband";//��
    if (a == "mom" && g == 0) return "wife";//�d
    if (a == "mom" && g == 1) return "me_female";//��(�k)
    if (a == "bro_old") return "son";//��l
    if (a == "bro_young") return "son";//��l
    if (a == "sis_old") return "daughter";//�k��
    if (a == "sis_young") return "daughter";//�k��
    if (a == "wife") return "son_wife";//�@��
    if (a == "daughter") return "son_daughter";//�]�k
    if (a == "daughter_old") return "son_daughter";//�]�k
    if (a == "daughter_young") return "son_daughter";//�]�k
    if (a == "son") return "son_son";//�]�l
    if (a == "son_old") return "son_son";//�]�l
    if (a == "son_young") return "son_son";//�]�l
}

string me_female(string a) {
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "bro_old";//����
    if (a == "bro_young") return "bro_young";//�̧�
    if (a == "sis_old") return "sis_old";//�n�n
    if (a == "sis_young") return "sis_young";//�f�f
    if (a == "husband") return "husband";//��
    if (a == "daughter") return "daughter";//�k��
    if (a == "daughter_old") return "daughter";//�k��
    if (a == "daughter_young") return "daughter";//�k��
    if (a == "son") return "son";//��l
    if (a == "son_old") return "son";//��l
    if (a == "son_young") return "son";//��l
}

string me_male(string a) {
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "bro_old";//����
    if (a == "bro_young") return "bro_young";//�̧�
    if (a == "sis_old") return "sis_old";//�n�n
    if (a == "sis_young") return "sis_young";//�f�f
    if (a == "wife") return "wife";//�d
    if (a == "daughter") return "daughter";//�k��
    if (a == "daughter_old") return "daughter";//�k��
    if (a == "daughter_young") return "daughter";//�k��
    if (a == "son") return "son";//��l
    if (a == "son_old") return "son";//��l
    if (a == "son_young") return "son";//��l
}

string me(string a) {
    if (a == "dad") return "dad";//����
    if (a == "mom") return "mom";//����
    if (a == "bro_old") return "bro_old";//����
    if (a == "bro_young") return "bro_young";//�̧�
    if (a == "sis_old") return "sis_old";//�n�n
    if (a == "sis_young") return "sis_young";//�f�f
    if (a == "husband") { g = 1; return "husband"; }//�� -------add
    if (a == "wife") { g = 0; return "wife"; }//�d -------------add
    if (a == "daughter") return "daughter";//�k��
    if (a == "daughter_old") return "daughter";//�k��
    if (a == "daughter_young") return "daughter";//�k��
    if (a == "son") return "son";//��l
    if (a == "son_old") return "son";//��l
    if (a == "son_young") return "son";//��l
}

string dad_dad(string a) {
    if (a == "dad") return "dad_dad_dad";//����
    if (a == "mom") return "dad_dad_mom";//����
    if (a == "bro_old") return "";//
    if (a == "bro_young") return "";//
    if (a == "sis_old") return "";//
    if (a == "sis_young") return "";//
    if (a == "wife") return "dad_mom";//����
    if (a == "daughter") return "dad_sis_old";//�h��
    if (a == "daughter_old") return "dad_sis_old";//�h��
    if (a == "daughter_young") return "dad_sis_young";//�h��
    if (a == "son") return "dad";//����(�w�])
    if (a == "son_old") return "dad_bro_old";//�B��
    if (a == "son_young") return "dad_bro_young";//����
}
string dad_mom(string a) {
    if (a == "dad") return "dad_dad_dad";//����
    if (a == "mom") return "dad_dad_mom";//����
    if (a == "bro_old") return "";//
    if (a == "bro_young") return "";//
    if (a == "sis_old") return "";//
    if (a == "sis_young") return "";//
    if (a == "husband") return "dad_dad";//����
    if (a == "daughter") return "dad_sis_old";//�h��
    if (a == "daughter_old") return "dad_sis_old";//�h��
    if (a == "daughter_young") return "dad_sis_young";//�h��
    if (a == "son") return "dad";//����(�w�])
    if (a == "son_old") return "dad_bro_old";//�B��
    if (a == "son_young") return "dad_bro_young";//����
}

string dad_bro_old(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "bro_old") return "dad_bro_old";//
    if (a == "bro_young") return "dad";//����(�w�])
    if (a == "sis_old") return "dad_sis_old";//�h��
    if (a == "sis_young") return "dad_sis_young";//�h��
    if (a == "wife") return "dad_bro_old_wife";//�B��
    if (a == "daughter") return "dad_bro_old_daughter_old";//��n
    if (a == "daughter_old") return "dad_bro_old_daughter_old";//��n
    if (a == "daughter_young") return "dad_bro_old_daughter_young";//��f
    if (a == "son") return "dad_bro_old_son_old";//���
    if (a == "son_old") return "dad_bro_old_son_old";//���
    if (a == "son_young") return "dad_bro_old_son_young";//���
}
string dad_bro_young(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "bro_old") return "dad";//����(�w�])
    if (a == "bro_young") return "dad_bro_young";//
    if (a == "sis_old") return "dad_sis_old";//�h��
    if (a == "sis_young") return "dad_sis_young";//�h��
    if (a == "wife") return "dad_bro_young_wife";//�T�T
    if (a == "daughter") return "dad_bro_young_daughter_old";//��n
    if (a == "daughter_old") return "dad_bro_young_daughter_old";//��n
    if (a == "daughter_young") return "dad_bro_young_daughter_young";//��f
    if (a == "son") return "dad_bro_young_son_old";//���
    if (a == "son_old") return "dad_bro_young_son_old";//���
    if (a == "son_young") return "dad_bro_young_son_young";//���
}
string dad_sis_old(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "bro_old") return "dad";//����(�w�])
    if (a == "bro_young") return "dad";//����(�w�])
    if (a == "sis_old") return "dad_sis_old";//�h��(�w�])
    if (a == "sis_young") return "dad_sis_young";//�h��(�w�])
    if (a == "husband") return "dad_sis_old_husband";//�h�V
    if (a == "daughter") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//��f
    if (a == "son") return "dad_sis_old_son_old";//��S
    if (a == "son_old") return "dad_sis_old_son_old";//��S
    if (a == "son_young") return "dad_sis_old_son_young";//���
}
string dad_sis_young(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "bro_old") return "dad";//����(�w�])
    if (a == "bro_young") return "dad";//����(�w�])
    if (a == "sis_old") return "dad_sis_old";//�h��(�w�])
    if (a == "sis_young") return "dad_sis_young";//�h��(�w�])
    if (a == "husband") return "dad_sis_young_husband";//�h�V
    if (a == "daughter") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//��f
    if (a == "son") return "dad_sis_old_son_old";//��S
    if (a == "son_old") return "dad_sis_old_son_old";//��S
    if (a == "son_young") return "dad_sis_old_son_young";//���
}

string dad_bro_old_wife(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "husband") return "dad_bro_old";//�B��
    if (a == "daughter") return "dad_bro_old_daughter_old";//��n
    if (a == "daughter_old") return "dad_bro_old_daughter_old";//��n
    if (a == "daughter_young") return "dad_bro_old_daughter_young";//��f
    if (a == "son") return "dad_bro_old_son_old";//���
    if (a == "son_old") return "dad_bro_old_son_old";//���
    if (a == "son_young") return "dad_bro_old_son_young";//���
}
string dad_bro_young_wife(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "husband") return "dad_bro_young";//����
    if (a == "daughter") return "dad_bro_young_daughter_old";//��n
    if (a == "daughter_old") return "dad_bro_young_daughter_old";//��n
    if (a == "daughter_young") return "dad_bro_young_daughter_young";//��f
    if (a == "son") return "dad_bro_young_son_old";//���
    if (a == "son_old") return "dad_bro_young_son_old";//���
    if (a == "son_young") return "dad_bro_young_son_young";//���
}
string dad_sis_old_husband(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "wife") return "dad_sis_old";//�h��
    if (a == "daughter") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//��f
    if (a == "son") return "dad_sis_old_son_old";//��S
    if (a == "son_old") return "dad_sis_old_son_old";//��S
    if (a == "son_young") return "dad_sis_old_son_young";//���
}
string dad_sis_young_husband(string a) {
    if (a == "dad") return "dad_dad";//����
    if (a == "mom") return "dad_mom";//����
    if (a == "wife") return "dad_sis_old";//�h��
    if (a == "daughter") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "dad_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "dad_sis_old_daughter_young";//��f
    if (a == "son") return "dad_sis_old_son_old";//��S
    if (a == "son_old") return "dad_sis_old_son_old";//��S
    if (a == "son_young") return "dad_sis_old_son_young";//���
}

string dad_bro_old_daughter_old(string a) {
    if (a == "dad") return "dad_bro_old";//�B��
    if (a == "mom") return "dad_bro_old_wife";//�B��
    if (a == "bro_old") return "dad_bro_old_son_old";//���
    if (a == "bro_young") return "dad_bro_old_son_young";//���
    if (a == "sis_old") return "dad_bro_old_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_old_daughter_young";//��f
}
string dad_bro_old_daughter_young(string a) {
    if (a == "dad") return "dad_bro_old";//�B��
    if (a == "mom") return "dad_bro_old_wife";//�B��
    if (a == "bro_old") return "dad_bro_old_son_old";//���
    if (a == "bro_young") return "dad_bro_old_son_young";//���
    if (a == "sis_old") return "dad_bro_old_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_old_daughter_young";//��f
}
string dad_bro_old_son_old(string a) {
    if (a == "dad") return "dad_bro_old";//�B��
    if (a == "mom") return "dad_bro_old_wife";//�B��
    if (a == "bro_old") return "dad_bro_old_son_old";//���
    if (a == "bro_young") return "dad_bro_old_son_young";//���
    if (a == "sis_old") return "dad_bro_old_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_old_daughter_young";//��n
}
string dad_bro_old_son_young(string a) {
    if (a == "dad") return "dad_bro_old";//�B��
    if (a == "mom") return "dad_bro_old_wife";//�B��
    if (a == "bro_old") return "dad_bro_old_son_old";//���
    if (a == "bro_young") return "dad_bro_old_son_young";//���
    if (a == "sis_old") return "dad_bro_old_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_old_daughter_young";//��f
}
string dad_bro_young_daughter_old(string a) {
    if (a == "dad") return "dad_bro_young";//����
    if (a == "mom") return "dad_bro_young_wife";//�T�T
    if (a == "bro_old") return "dad_bro_young_son_old";//���
    if (a == "bro_young") return "dad_bro_young_son_young";//���
    if (a == "sis_old") return "dad_bro_young_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_young_daughter_young";//��f
}
string dad_bro_young_daughter_young(string a) {
    if (a == "dad") return "dad_bro_young";//����
    if (a == "mom") return "dad_bro_young_wife";//�T�T
    if (a == "bro_old") return "dad_bro_young_son_old";//���
    if (a == "bro_young") return "dad_bro_young_son_young";//���
    if (a == "sis_old") return "dad_bro_young_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_young_daughter_young";//��f
}
string dad_bro_young_son_old(string a) {
    if (a == "dad") return "dad_bro_young";//����
    if (a == "mom") return "dad_bro_young_wife";//�T�T
    if (a == "bro_old") return "dad_bro_young_son_old";//���
    if (a == "bro_young") return "dad_bro_young_son_young";//���
    if (a == "sis_old") return "dad_bro_young_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_young_daughter_young";//��f
}
string dad_bro_young_son_young(string a) {
    if (a == "dad") return "dad_bro_young";//����
    if (a == "mom") return "dad_bro_young_wife";//�T�T
    if (a == "bro_old") return "dad_bro_young_son_old";//���
    if (a == "bro_young") return "dad_bro_young_son_young";//���
    if (a == "sis_old") return "dad_bro_young_daughter_old";//��n
    if (a == "sis_young") return "dad_bro_young_daughter_young";//��f
}
string dad_sis_old_daughter_old(string a) {
    if (a == "dad") return "dad_sis_old_husband";//����
    if (a == "mom") return "dad_sis_old";//����
    if (a == "bro_old") return "dad_sis_old_son_old";//���
    if (a == "bro_young") return "dad_sis_old_son_young";//���
    if (a == "sis_old") return "dad_sis_old_daughter_old";//��n
    if (a == "sis_young") return "dad_sis_old_daughter_young";//��f
}
string dad_sis_old_daughter_young(string a) {
    if (a == "dad") return "dad_sis_old_husband";//����
    if (a == "mom") return "dad_sis_old";//����
    if (a == "bro_old") return "dad_sis_old_son_old";//���
    if (a == "bro_young") return "dad_sis_old_son_young";//���
    if (a == "sis_old") return "dad_sis_old_daughter_old";//��n
    if (a == "sis_young") return "dad_sis_old_daughter_young";//��f
}
string dad_sis_old_son_old(string a) {
    if (a == "dad") return "dad_sis_old_husband";//����
    if (a == "mom") return "dad_sis_old";//����
    if (a == "bro_old") return "dad_sis_old_son_old";//���
    if (a == "bro_young") return "dad_sis_old_son_young";//���
    if (a == "sis_old") return "dad_sis_old_daughter_old";//��n
    if (a == "sis_young") return "dad_sis_old_daughter_young";//��f
}
string dad_sis_old_son_young(string a) {
    if (a == "dad") return "dad_sis_old_husband";//����
    if (a == "mom") return "dad_sis_old";//����
    if (a == "bro_old") return "dad_sis_old_son_old";//���
    if (a == "bro_young") return "dad_sis_old_son_young";//���
    if (a == "sis_old") return "dad_sis_old_daughter_old";//��n
    if (a == "sis_young") return "dad_sis_old_daughter_young";//��f
}
bool m = 0;
string mom_dad(string a) {
    if (a == "wife") return "mom_mom";//�~����
    if (a == "daughter") return "mom_sis_old";//����(�w�])
    if (a == "daughter" && m ==1) return "mom";//����(�w�])
    if (a == "daughter_old") return "mom_sis_old";//����
    if (a == "daughter_young") return "mom_sis_young";//����
    if (a == "son") return "mom_bro_old";//����
    if (a == "son_old") return "mom_bro_old";//����
    if (a == "son_young") return "mom_bro_old";//����
}
string mom_mom(string a) {
    if (a == "husband") return "mom_dad";//�~����
    if (a == "daughter") return "mom_sis_old";//����(�w�])
    if (a == "daughter" && m ==1) return "mom";//����(�w�])
    if (a == "daughter_old") return "mom_sis_old";//����
    if (a == "daughter_young") return "mom_sis_young";//����
    if (a == "son") return "mom_bro_old";//����
    if (a == "son_old") return "mom_bro_old";//����
    if (a == "son_young") return "mom_bro_old";//����
}

string mom_bro_old(string a) {
    if (a == "dad") return "mom_dad";//�~����
    if (a == "mom") return "mom_mom";//�~����
    if (a == "bro_old") return "mom_bro_old";//����
    if (a == "bro_young") return "mom_bro_young";//����
    if (a == "sis_old") return "mom";//����
    if (a == "sis_young") return "mom";//����(�w�])
    if (a == "wife") return "mom_bro_old_wife";//����
    if (a == "daughter") return "mom_bro_old_daughter_old";//��n
    if (a == "daughter_old") return "mom_bro_old_daughter_old";//��n
    if (a == "daughter_young") return "mom_bro_old_daughter_young";//��f
    if (a == "son") return "mom_bro_old_son_old";//���
    if (a == "son_old") return "mom_bro_old_son_old";//���
    if (a == "son_young") return "mom_bro_old_son_young";//���
}
string mom_bro_young(string a) {
    if (a == "dad") return "mom_dad";//�~����
    if (a == "mom") return "mom_mom";//�~����
    if (a == "bro_old") return "mom_bro_old";//����
    if (a == "bro_young") return "mom_bro_young";//����
    if (a == "sis_old") return "mom";//����
    if (a == "sis_young") return "mom";//����(�w�])
    if (a == "wife") return "mom_bro_old_wife";//����
    if (a == "daughter") return "mom_bro_old_daughter_old";//��n
    if (a == "daughter_old") return "mom_bro_old_daughter_old";//��n
    if (a == "daughter_young") return "mom_bro_old_daughter_young";//��f
    if (a == "son") return "mom_bro_old_son_old";//���
    if (a == "son_old") return "mom_bro_old_son_old";//���
    if (a == "son_young") return "mom_bro_old_son_young";//���
}
string mom_sis_old(string a) {
    if (a == "dad") return "mom_dad";//�~����
    if (a == "mom") return "mom_mom";//�~����
    if (a == "bro_old") return "mom_bro_old";//����
    if (a == "bro_young") return "mom_bro_old";//����
    if (a == "sis_old") return "mom_sis_old";//����
    if (a == "sis_young") return "mom";//����(�w�])
    if (a == "husband") return "mom_sis_old_husband";//���V
    if (a == "daughter") return "mom_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "mom_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "mom_sis_old_daughter_young";//��f
    if (a == "son") return "mom_sis_old_son_old";//���
    if (a == "son_old") return "mom_sis_old_son_old";//���
    if (a == "son_young") return "mom_sis_old_son_young";//���
}
string mom_sis_young(string a) {
    if (a == "dad") return "mom_dad";//�~����
    if (a == "mom") return "mom_mom";//�~����
    if (a == "bro_old") return "mom_bro_old";//����
    if (a == "bro_young") return "mom_bro_old";//����
    if (a == "sis_old") return "mom";//����
    if (a == "sis_young") return "mom_sis_young";//����(�w�])
    if (a == "husband") return "mom_sis_old_husband";//���V
    if (a == "daughter") return "mom_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "mom_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "mom_sis_old_daughter_young";//��f
    if (a == "son") return "mom_sis_old_son_old";//���
    if (a == "son_old") return "mom_sis_old_son_old";//���
    if (a == "son_young") return "mom_sis_old_son_young";//���
}
string mom_bro_old_wife(string a) {
    if (a == "husband") return "mom_bro_old";//����
    if (a == "daughter") return "mom_bro_old_daughter_old";//��n
    if (a == "daughter_old") return "mom_bro_old_daughter_old";//��n
    if (a == "daughter_young") return "mom_bro_old_daughter_young";//��f
    if (a == "son") return "mom_bro_old_son_old";//���
    if (a == "son_old") return "mom_bro_old_son_old";//���
    if (a == "son_young") return "mom_bro_old_son_young";//���
}
string mom_sis_old_husband(string a) {
    if (a == "wife") return "mom_sis_old";//����
    if (a == "daughter") return "mom_sis_old_daughter_old";//��n
    if (a == "daughter_old") return "mom_sis_old_daughter_old";//��n
    if (a == "daughter_young") return "mom_sis_old_daughter_young";//��f
    if (a == "son") return "mom_sis_old_son_old";//���
    if (a == "son_old") return "mom_sis_old_son_old";//���
    if (a == "son_young") return "mom_sis_old_son_young";//���
}

string mom_bro_old_daughter_old(string a) {
    if (a == "dad") return "mom_bro_old";//����
    if (a == "mom") return "mom_bro_old_wife";//����
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_bro_old_daughter_young(string a) {
    if (a == "dad") return "mom_bro_old";//����
    if (a == "mom") return "mom_bro_old_wife";//����
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_bro_old_son_old(string a) {
    if (a == "dad") return "mom_bro_old";//����
    if (a == "mom") return "mom_bro_old_wife";//����
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_bro_old_son_young(string a) {
    if (a == "dad") return "mom_bro_old";//����
    if (a == "mom") return "mom_bro_old_wife";//����
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_sis_old_daughter_old(string a) {
    if (a == "mom") return "mom_sis_old";//����
    if (a == "dad") return "mom_sis_old_husband";//���V
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_sis_old_daughter_young(string a) {
    if (a == "mom") return "mom_sis_old";//����
    if (a == "dad") return "mom_sis_old_husband";//���V
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_sis_old_son_old(string a) {
    if (a == "mom") return "mom_sis_old";//����
    if (a == "dad") return "mom_sis_old_husband";//���V
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}
string mom_sis_old_son_young(string a) {
    if (a == "mom") return "mom_sis_old";//����
    if (a == "dad") return "mom_sis_old_husband";//���V
    if (a == "bro_old") return "mom_bro_old_son_old";//���
    if (a == "bro_young") return "mom_bro_old_son_young";//���
    if (a == "sis_old") return "mom_bro_old_daughter_old";//��n
    if (a == "sis_young") return "mom_bro_old_daughter_young";//��f
}

string bro_old_wife(string a) {
    if (a == "husband") return "bro_old";//����
    if (a == "daughter") return "bro_old_daughter";//���k
    if (a == "daughter_old") return "bro_old_daughter";//���k
    if (a == "daughter_young") return "bro_old_daughter";//���k
    if (a == "son") return "bro_old_son";//���l
    if (a == "son_old") return "bro_old_son";//���l
    if (a == "son_young") return "bro_old_son";//���l
}
string bro_old_daughter(string a) {
    if (a == "dad") return "bro_old";//����
    if (a == "mom") return "bro_old_wife";//�A�A
    if (a == "bro_old") return "bro_old_son";//���l
    if (a == "bro_young") return "bro_old_son";//���l
    if (a == "sis_old") return "bro_old_daughter";//���k
    if (a == "sis_young") return "bro_old_daughter";//���k
}
string bro_old_son(string a) {
    if (a == "dad") return "bro_old";//����
    if (a == "mom") return "bro_old_wife";//�A�A
    if (a == "bro_old") return "bro_old_son";//���l
    if (a == "bro_young") return "bro_old_son";//���l
    if (a == "sis_old") return "bro_old_daughter";//���k
    if (a == "sis_young") return "bro_old_daughter";//���k
}

string bro_young_wife(string a) {
    if (a == "husband") return "bro_young";//�̧�
    if (a == "daughter") return "bro_young_daughter";//���k
    if (a == "daughter_old") return "bro_young_daughter";//���k
    if (a == "daughter_young") return "bro_young_daughter";//���k
    if (a == "son") return "bro_young_son";//���l
    if (a == "son_old") return "bro_young_son";//���l
    if (a == "son_young") return "bro_young_son";//���l
}
string bro_young_daughter(string a) {
    if (a == "dad") return "bro_young";//�̧�
    if (a == "mom") return "bro_young_wife";//�̷@
    if (a == "bro_old") return "bro_young_son";//���l
    if (a == "bro_young") return "bro_young_son";//���l
    if (a == "sis_old") return "bro_young_daughter";//���k
    if (a == "sis_young") return "bro_young_daughter";//���k
}
string bro_young_son(string a) {
    if (a == "dad") return "bro_young";//�̧�
    if (a == "mom") return "bro_young_wife";//�̷@
    if (a == "bro_old") return "bro_young_son";//���l
    if (a == "bro_young") return "bro_young_son";//���l
    if (a == "sis_old") return "bro_young_daughter";//���k
    if (a == "sis_young") return "bro_young_daughter";//���k
}

string sis_old_husband(string a) {
    if (a == "wife") return "sis_old";//�n�n
    if (a == "daughter") return "sis_old_daughter";//�~�c�k
    if (a == "daughter_old") return "sis_old_daughter";//�~�c�k
    if (a == "daughter_young") return "sis_old_daughter";//�~�c�k
    if (a == "son") return "sis_old_son";//�~�c
    if (a == "son_old") return "sis_old_son";//�~�c
    if (a == "son_young") return "sis_old_son";//�~�c
}
string sis_old_daughter(string a) {
    if (a == "dad") return "sis_old_husband";//�n��
    if (a == "mom") return "sis_old";//�n�n
    if (a == "bro_old") return "sis_old_son";//�~�c
    if (a == "bro_young") return "sis_old_son";//�~�c
    if (a == "sis_old") return "sis_old_daughter";//�~�c�k
    if (a == "sis_young") return "sis_old_daughter";//�~�c�k
}
string sis_old_son(string a) {
    if (a == "dad") return "sis_old_husband";//�n��
    if (a == "mom") return "sis_old";//�n�n
    if (a == "bro_old") return "sis_old_son";//�~�c
    if (a == "bro_young") return "sis_old_son";//�~�c
    if (a == "sis_old") return "sis_old_daughter";//�~�c�k
    if (a == "sis_young") return "sis_old_daughter";//�~�c�k
}

string sis_young_husband(string a) {
    if (a == "wife") return "sis_young";//�f�f
    if (a == "daughter") return "sis_young_daughter";//�~�c�k
    if (a == "daughter_old") return "sis_young_daughter";//�~�c�k
    if (a == "daughter_young") return "sis_young_daughter";//�~�c�k
    if (a == "son") return "sis_young_son";//�~�c
    if (a == "son_old") return "sis_young_son";//�~�c
    if (a == "son_young") return "sis_young_son";//�~�c
}
string sis_young_daughter(string a) {
    if (a == "dad") return "sis_young_husband";//�f��
    if (a == "mom") return "sis_young";//�f�f
    if (a == "bro_old") return "sis_young_son";//�~�c
    if (a == "bro_young") return "sis_young_son";//�~�c
    if (a == "sis_old") return "sis_young_daughter";//�~�c�k
    if (a == "sis_young") return "sis_young_daughter";//�~�c�k
}
string sis_young_son(string a) {
    if (a == "dad") return "sis_young_husband";//�f��
    if (a == "mom") return "sis_young";//�f�f
    if (a == "bro_old") return "sis_young_son";//�~�c
    if (a == "bro_young") return "sis_young_son";//�~�c
    if (a == "sis_old") return "sis_young_daughter";//�~�c�k
    if (a == "sis_young") return "sis_young_daughter";//�~�c�k
}

string husband_dad(string a) {
    if (a == "wife") return "husband_mom";//�ҥ�
    if (a == "daughter") return "husband_sis_old";//�ҩn
    if (a == "daughter_old") return "husband_sis_old";//�ҩn
    if (a == "daughter_young") return "husband_sis_young";//�ҩf
    if (a == "son") return "husband";//��
    if (a == "son_old") return "husband_bro_old";//�ҥS
    if (a == "son_young") return "husband_bro_young";//�ҧ�
}
string husband_mom(string a) {
    if (a == "husband") return "husband_dad";//�Ҥ�
    if (a == "daughter") return "husband_sis_old";//�ҩn
    if (a == "daughter_old") return "husband_sis_old";//�ҩn
    if (a == "daughter_young") return "husband_sis_young";//�ҩf
    if (a == "son") return "husband";//��
    if (a == "son_old") return "husband_bro_old";//�ҥS
    if (a == "son_young") return "husband_bro_young";//�ҧ�
}

string husband_bro_old(string a) {
    if (a == "dad") return "husband_dad";//�Ҥ�
    if (a == "mom") return "husband_mom";//�ҥ�
    if (a == "bro_old") return "husband_bro_old";//�ҥS
    if (a == "bro_young") return "husband";//��
    if (a == "sis_old") return "husband_sis_old";//�ҩn
    if (a == "sis_young") return "husband_sis_young";//�ҩf
    if (a == "wife") return "husband_bro_old_wife";//�ҥS�A
    if (a == "daughter") return "husband_bro_old_daughter";//���k
    if (a == "daughter_old") return "husband_bro_old_daughter";//���k
    if (a == "daughter_young") return "husband_bro_old_daughter";//���k
    if (a == "son") return "husband_bro_old_son";//���l
    if (a == "son_old") return "husband_bro_old_son";//���l
    if (a == "son_young") return "husband_bro_old_son";//���l
}
string husband_bro_young(string a) {
    if (a == "dad") return "husband_dad";//�Ҥ�
    if (a == "mom") return "husband_mom";//�ҥ�
    if (a == "bro_old") return "husband";//��
    if (a == "bro_young") return "husband_bro_young";//�ҧ�
    if (a == "sis_old") return "husband_sis_old";//�ҩn
    if (a == "sis_young") return "husband_sis_young";//�ҩf
    if (a == "wife") return "husband_bro_young_wife";//�ҧ̷@
    if (a == "daughter") return "husband_bro_young_daughter";//���k
    if (a == "daughter_old") return "husband_bro_young_daughter";//���k
    if (a == "daughter_young") return "husband_bro_young_daughter";//���k
    if (a == "son") return "husband_bro_young_son";//���l
    if (a == "son_old") return "husband_bro_young_son";//���l
    if (a == "son_young") return "husband_bro_young_son";//���l
}
string husband_sis_old(string a) {
    if (a == "dad") return "husband_dad";//�Ҥ�
    if (a == "mom") return "husband_mom";//�ҥ�
    if (a == "bro_old") return "husband_bro_old";//�ҥS
    if (a == "bro_young") return "husband_bro_young";//�ҧ�
    if (a == "sis_old") return "husband_sis_old";//�ҩn
    if (a == "sis_young") return "husband_sis_young";//�ҩf
    if (a == "husband") return "husband_sis_old_husband";//�ҩn��
    if (a == "daughter") return "husband_sis_old_daughter";//�~�c�k
    if (a == "daughter_old") return "husband_sis_old_daughter";//�~�c�k
    if (a == "daughter_young") return "husband_sis_old_daughter";//�~�c�k
    if (a == "son") return "husband_sis_old_son";//�~�c
    if (a == "son_old") return "husband_sis_old_son";//�~�c
    if (a == "son_young") return "husband_sis_old_son";//�~�c
}
string husband_sis_young(string a) {
    if (a == "dad") return "husband_dad";//�Ҥ�
    if (a == "mom") return "husband_mom";//�ҥ�
    if (a == "bro_old") return "husband_bro_old";//�ҥS
    if (a == "bro_young") return "husband_bro_young";//�ҧ�
    if (a == "sis_old") return "husband_sis_old";//�ҩn
    if (a == "sis_young") return "husband_sis_young";//�ҩf
    if (a == "husband") return "husband_sis_young_husband";//�ҩf��
    if (a == "daughter") return "husband_sis_young_daughter";//�~�c�k
    if (a == "daughter_old") return "husband_sis_young_daughter";//�~�c�k
    if (a == "daughter_young") return "husband_sis_young_daughter";//�~�c�k
    if (a == "son") return "husband_sis_young_son";//�~�c
    if (a == "son_old") return "husband_sis_young_son";//�~�c
    if (a == "son_young") return "husband_sis_young_son";//�~�c
}

string husband_bro_old_wife(string a) {
    if (a == "husband") return "husband_bro_old";//�ҥS
    if (a == "daughter") return "husband_bro_old_daughter";//���k
    if (a == "daughter_old") return "husband_bro_old_daughter";//���k
    if (a == "daughter_young") return "husband_bro_old_daughter";//���k
    if (a == "son") return "husband_bro_old_son";//���l
    if (a == "son_old") return "husband_bro_old_son";//���l
    if (a == "son_young") return "husband_bro_old_son";//���l
}
string husband_bro_young_wife(string a) {
    if (a == "husband") return "husband_bro_young";//�ҧ�
    if (a == "daughter") return "husband_bro_young_daughter";//���k
    if (a == "daughter_old") return "husband_bro_young_daughter";//���k
    if (a == "daughter_young") return "husband_bro_young_daughter";//���k
    if (a == "son") return "husband_bro_young_son";//���l
    if (a == "son_old") return "husband_bro_young_son";//���l
    if (a == "son_young") return "husband_bro_young_son";//���l
}
string husband_sis_old_husband(string a) {
    if (a == "wife") return "husband_sis_old";//�ҩn
    if (a == "daughter") return "husband_sis_old_daughter";//�~�c�k
    if (a == "daughter_old") return "husband_sis_old_daughter";//�~�c�k
    if (a == "daughter_young") return "husband_sis_old_daughter";//�~�c�k
    if (a == "son") return "husband_sis_old_son";//�~�c
    if (a == "son_old") return "husband_sis_old_son";//�~�c
    if (a == "son_young") return "husband_sis_old_son";//�~�c
}
string husband_sis_young_husband(string a) {
    if (a == "wife") return "husband_sis_young";//�ҩf
    if (a == "daughter") return "husband_sis_young_daughter";//�~�c�k
    if (a == "daughter_old") return "husband_sis_young_daughter";//�~�c�k
    if (a == "daughter_young") return "husband_sis_young_daughter";//�~�c�k
    if (a == "son") return "husband_sis_young_son";//�~�c
    if (a == "son_old") return "husband_sis_young_son";//�~�c
    if (a == "son_young") return "husband_sis_young_son";//�~�c
}

string husband_bro_old_daughter(string a) {
    if (a == "dad") return "husband_bro_old";//�ҥS
    if (a == "mom") return "husband_bro_old_wife";//�ҥS�A
    if (a == "bro_old") return "husband_bro_old_son";//���l
    if (a == "bro_young") return "husband_bro_old_son";//���l
    if (a == "sis_old") return "husband_bro_old_daughter";//���k
    if (a == "sis_young") return "husband_bro_old_daughter";//���k
}
string husband_bro_old_son(string a) {
    if (a == "dad") return "husband_bro_old";//�ҥS
    if (a == "mom") return "husband_bro_old_wife";//�ҥS�A
    if (a == "bro_old") return "husband_bro_old_son";//���l
    if (a == "bro_young") return "husband_bro_old_son";//���l
    if (a == "sis_old") return "husband_bro_old_daughter";//���k
    if (a == "sis_young") return "husband_bro_old_daughter";//���k
}
string husband_bro_young_daughter(string a) {
    if (a == "dad") return "husband_bro_young";//�ҧ�
    if (a == "mom") return "husband_bro_young_wife";//�ҧ̷@
    if (a == "bro_old") return "husband_bro_young_son";//���l
    if (a == "bro_young") return "husband_bro_young_son";//���l
    if (a == "sis_old") return "husband_bro_young_daughter";//���k
    if (a == "sis_young") return "husband_bro_young_daughter";//���k
}
string husband_bro_young_son(string a) {
    if (a == "dad") return "husband_bro_young";//�ҧ�
    if (a == "mom") return "husband_bro_young_wife";//�ҧ̷@
    if (a == "bro_old") return "husband_bro_young_son";//���l
    if (a == "bro_young") return "husband_bro_young_son";//���l
    if (a == "sis_old") return "husband_bro_young_daughter";//���k
    if (a == "sis_young") return "husband_bro_young_daughter";//���k
}
string husband_sis_old_daughter(string a) {
    if (a == "dad") return "husband_sis_old_husband";//�ҩn��
    if (a == "mom") return "husband_sis_old";//�ҩn
    if (a == "bro_old") return "husband_sis_old_son";//�~�c
    if (a == "bro_young") return "husband_sis_old_son";//�~�c
    if (a == "sis_old") return "husband_sis_old_daughter";//�~�c�k
    if (a == "sis_young") return "husband_sis_old_daughter";//�~�c�k
}
string husband_sis_old_son(string a) {
    if (a == "dad") return "husband_sis_old_husband";//�ҩn��
    if (a == "mom") return "husband_sis_old";//�ҩn
    if (a == "bro_old") return "husband_sis_old_son";//�~�c
    if (a == "bro_young") return "husband_sis_old_son";//�~�c
    if (a == "sis_old") return "husband_sis_old_daughter";//�~�c�k
    if (a == "sis_young") return "husband_sis_old_daughter";//�~�c�k
}
string husband_sis_young_daughter(string a) {
    if (a == "dad") return "husband_sis_young_husband";//�ҩf��
    if (a == "mom") return "husband_sis_young";//�ҩf
    if (a == "bro_old") return "husband_sis_young_son";//�~�c
    if (a == "bro_young") return "husband_sis_young_son";//�~�c
    if (a == "sis_old") return "husband_sis_young_daughter";//�~�c�k
    if (a == "sis_young") return "husband_sis_young_daughter";//�~�c�k
}
string husband_sis_young_son(string a) {
    if (a == "dad") return "husband_sis_young_husband";//�ҩf��
    if (a == "mom") return "husband_sis_young";//�ҩf
    if (a == "bro_old") return "husband_sis_young_son";//�~�c
    if (a == "bro_young") return "husband_sis_young_son";//�~�c
    if (a == "sis_old") return "husband_sis_young_daughter";//�~�c�k
    if (a == "sis_young") return "husband_sis_young_daughter";//�~�c�k
}

string wife_dad(string a) {
    if (a == "wife") return "wife_mom";//�d��
    if (a == "daughter") return "wife";//�d
    if (a == "daughter_old") return "wife_sis_old";//�d�n
    if (a == "daughter_young") return "wife_sis_young";//�d�f
    if (a == "son") return "wife_bro_old";//�d�S
    if (a == "son_old") return "wife_bro_old";//�d�S
    if (a == "son_young") return "wife_bro_young";//�d��
}
string wife_mom(string a) {
    if (a == "husband") return "wife_dad";//�d��
    if (a == "daughter") return "wife";//�d
    if (a == "daughter_old") return "wife_sis_old";//�d�n
    if (a == "daughter_young") return "wife_sis_young";//�d�f
    if (a == "son") return "wife_bro_old";//�d�S
    if (a == "son_old") return "wife_bro_old";//�d�S
    if (a == "son_young") return "wife_bro_young";//�d��
}

string wife_bro_old(string a) {
    if (a == "dad") return "wife_dad";//�d��
    if (a == "mom") return "wife_mom";//�d��
    if (a == "bro_old") return "wife_bro_old";//�d�S
    if (a == "bro_young") return "wife_bro_young";//�d��
    if (a == "sis_old") return "wife_sis_old";//�d�n
    if (a == "sis_young") return "wife";//�d
    if (a == "wife") return "wife_bro_old_wife";//�d�S�A
    if (a == "daughter") return "wife_bro_old_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_bro_old_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_bro_old_daughter";//�~�c�k
    if (a == "son") return "wife_bro_old_son";//�~�c
    if (a == "son_old") return "wife_bro_old_son";//�~�c
    if (a == "son_young") return "wife_bro_old_son";//�~�c
}
string wife_bro_young(string a) {
    if (a == "dad") return "wife_dad";//�d��
    if (a == "mom") return "wife_mom";//�d��
    if (a == "bro_old") return "wife_bro_old";//�d�S
    if (a == "bro_young") return "wife_bro_young";//�d��
    if (a == "sis_old") return "wife";//�d
    if (a == "sis_young") return "wife_sis_young";//�d�f
    if (a == "wife") return "wife_bro_young_wife";//�d�̷@
    if (a == "daughter") return "wife_bro_young_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_bro_young_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_bro_young_daughter";//�~�c�k
    if (a == "son") return "wife_bro_young_son";//�~�c
    if (a == "son_old") return "wife_bro_young_son";//�~�c
    if (a == "son_young") return "wife_bro_young_son";//�~�c
}
string wife_sis_old(string a) {
    if (a == "dad") return "wife_dad";//�d��
    if (a == "mom") return "wife_mom";//�d��
    if (a == "bro_old") return "wife_bro_old";//�d�S
    if (a == "bro_young") return "wife_bro_young";//�d��
    if (a == "sis_old") return "wife_sis_old";//�d�n
    if (a == "sis_young") return "wife";//�d
    if (a == "husband") return "wife_sis_old_husband";//�d�n��
    if (a == "daughter") return "wife_sis_old_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_sis_old_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_sis_old_daughter";//�~�c�k
    if (a == "son") return "wife_sis_old_son";//�~�c
    if (a == "son_old") return "wife_sis_old_son";//�~�c
    if (a == "son_young") return "wife_sis_old_son";//�~�c
}
string wife_sis_young(string a) {
    if (a == "dad") return "wife_dad";//�d��
    if (a == "mom") return "wife_mom";//�d��
    if (a == "bro_old") return "wife_bro_old";//�d�S
    if (a == "bro_young") return "wife_bro_young";//�d��
    if (a == "sis_old") return "wife";//�d
    if (a == "sis_young") return "wife_sis_young";//�d�f
    if (a == "husband") return "wife_sis_young_husband";//�d�f��
    if (a == "daughter") return "wife_sis_young_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_sis_young_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_sis_young_daughter";//�~�c�k
    if (a == "son") return "wife_sis_young_son";//�~�c
    if (a == "son_old") return "wife_sis_young_son";//�~�c
    if (a == "son_young") return "wife_sis_young_son";//�~�c
}

string wife_bro_old_wife(string a) {
    if (a == "husband") return "wife_bro_old";//�d�S
    if (a == "daughter") return "wife_bro_old_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_bro_old_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_bro_old_daughter";//�~�c�k
    if (a == "son") return "wife_bro_old_son";//�~�c
    if (a == "son_old") return "wife_bro_old_son";//�~�c
    if (a == "son_young") return "wife_bro_old_son";//�~�c
}
string wife_bro_young_wife(string a) {
    if (a == "husband") return "wife_bro_young";//�d��
    if (a == "daughter") return "wife_bro_young_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_bro_young_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_bro_young_daughter";//�~�c�k
    if (a == "son") return "wife_bro_young_son";//�~�c
    if (a == "son_old") return "wife_bro_young_son";//�~�c
    if (a == "son_young") return "wife_bro_young_son";//�~�c
}
string wife_sis_old_husband(string a) {
    if (a == "wife") return "wife_sis_old";//�d�n
    if (a == "daughter") return "wife_sis_old_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_sis_old_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_sis_old_daughter";//�~�c�k
    if (a == "son") return "wife_sis_old_son";//�~�c
    if (a == "son_old") return "wife_sis_old_son";//�~�c
    if (a == "son_young") return "wife_sis_old_son";//�~�c
}
string wife_sis_young_husband(string a) {
    if (a == "wife") return "wife_sis_young";//�d�f
    if (a == "daughter") return "wife_sis_young_daughter";//�~�c�k
    if (a == "daughter_old") return "wife_sis_young_daughter";//�~�c�k
    if (a == "daughter_young") return "wife_sis_young_daughter";//�~�c�k
    if (a == "son") return "wife_sis_young_son";//�~�c
    if (a == "son_old") return "wife_sis_young_son";//�~�c
    if (a == "son_young") return "wife_sis_young_son";//�~�c
}

string wife_bro_old_daughter(string a) {
    if (a == "dad") return "wife_bro_old";//�d�S
    if (a == "mom") return "wife_bro_old_wife";//�d�S�A
    if (a == "bro_old") return "wife_bro_old_son";//�~�c
    if (a == "bro_young") return "wife_bro_old_son";//�~�c
    if (a == "sis_old") return "wife_bro_old_daughter";//�~�c�k
    if (a == "sis_young") return "wife_bro_old_daughter";//�~�c�k
}
string wife_bro_old_son(string a) {
    if (a == "dad") return "wife_bro_old";//�d�S
    if (a == "mom") return "wife_bro_old_wife";//�d�S�A
    if (a == "bro_old") return "wife_bro_old_son";//�~�c
    if (a == "bro_young") return "wife_bro_old_son";//�~�c
    if (a == "sis_old") return "wife_bro_old_daughter";//�~�c�k
    if (a == "sis_young") return "wife_bro_old_daughter";//�~�c�k
}
string wife_bro_young_daughter(string a) {
    if (a == "dad") return "wife_bro_young";//�d��
    if (a == "mom") return "wife_bro_young_wife";//�d�̷@
    if (a == "bro_old") return "wife_bro_young_son";//�~�c
    if (a == "bro_young") return "wife_bro_young_son";//�~�c
    if (a == "sis_old") return "wife_bro_young_daughter";//�~�c�k
    if (a == "sis_young") return "wife_bro_young_daughter";//�~�c�k
}
string wife_bro_young_son(string a) {
    if (a == "dad") return "wife_bro_young";//�d��
    if (a == "mom") return "wife_bro_young_wife";//�d�̷@
    if (a == "bro_old") return "wife_bro_young_son";//�~�c
    if (a == "bro_young") return "wife_bro_young_son";//�~�c
    if (a == "sis_old") return "wife_bro_young_daughter";//�~�c�k
    if (a == "sis_young") return "wife_bro_young_daughter";//�~�c�k
}
string wife_sis_old_daughter(string a) {
    if (a == "mom") return "wife_sis_old";//�d�n
    if (a == "dad") return "wife_sis_old_husband";//�d�n��
    if (a == "bro_old") return "wife_sis_old_son";//�~�c
    if (a == "bro_young") return "wife_sis_old_son";//�~�c
    if (a == "sis_old") return "wife_sis_old_daughter";//�~�c�k
    if (a == "sis_young") return "wife_sis_old_daughter";//�~�c�k
}
string wife_sis_old_son(string a) {
    if (a == "mom") return "wife_sis_old";//�d�n
    if (a == "dad") return "wife_sis_old_husband";//�d�n��
    if (a == "bro_old") return "wife_sis_old_son";//�~�c
    if (a == "bro_young") return "wife_sis_old_son";//�~�c
    if (a == "sis_old") return "wife_sis_old_daughter";//�~�c�k
    if (a == "sis_young") return "wife_sis_old_daughter";//�~�c�k
}
string wife_sis_young_daughter(string a) {
    if (a == "mom") return "wife_sis_young";//�d�f
    if (a == "dad") return "wife_sis_young_husband";//�d�f��
    if (a == "bro_old") return "wife_sis_young_son";//�~�c
    if (a == "bro_young") return "wife_sis_young_son";//�~�c
    if (a == "sis_old") return "wife_sis_young_daughter";//�~�c�k
    if (a == "sis_young") return "wife_sis_young_daughter";//�~�c�k
}
string wife_sis_young_son(string a) {
    if (a == "mom") return "wife_sis_young";//�d�f
    if (a == "dad") return "wife_sis_young_husband";//�d�f��
    if (a == "bro_old") return "wife_sis_young_son";//�~�c
    if (a == "bro_young") return "wife_sis_young_son";//�~�c
    if (a == "sis_old") return "wife_sis_young_daughter";//�~�c�k
    if (a == "sis_young") return "wife_sis_young_daughter";//�~�c�k
}

string daughter_husband(string a) {
    if (a == "wife") return "daughter";//�k��
    if (a == "daughter") return "daughter_daughter";//�~�]
    if (a == "daughter_old") return "daughter_daughter";//�~�]
    if (a == "daughter_young") return "daughter_daughter";//�~�]
    if (a == "son") return "daughter_son";//�~�]
    if (a == "son_old") return "daughter_son";//�~�]
    if (a == "son_young") return "daughter_son";//�~�]
}
string daughter_daughter(string a) {
    if (a == "dad" && g == 0) return "daughter_husband";//�k�B
    if (a == "dad" && g == 1) return "daughter_husband";//�k�B
    if (a == "mom" && g == 0) return "daughter";//�k��
    if (a == "mom" && g == 1) return "daughter";//�k��
    if (a == "bro_old") return "daughter_son";//�~�]
    if (a == "bro_young") return "daughter_son";//�~�]
    if (a == "sis_old") return "daughter_daughter";//�~�]
    if (a == "sis_young") return "daughter_daughter";//�~�]
}
string daughter_son(string a) {
    if (a == "dad" && g == 0) return "daughter_husband";//�k�B
    if (a == "dad" && g == 1) return "daughter_husband";//�k�B
    if (a == "mom" && g == 0) return "daughter";//�k��
    if (a == "mom" && g == 1) return "daughter";//�k��
    if (a == "bro_old") return "daughter_son";//�~�]
    if (a == "bro_young") return "daughter_son";//�~�]
    if (a == "sis_old") return "daughter_daughter";//�~�]
    if (a == "sis_young") return "daughter_daughter";//�~�]
}

string son_wife(string a) {
    if (a == "husband") return "son";//��l
    if (a == "daughter") return "son_daughter";//�]�k
    if (a == "daughter_old") return "son_daughter";//�]�k
    if (a == "daughter_young") return "son_daughter";//�]�k
    if (a == "son") return "son_son";//�]�l
    if (a == "son_old") return "son_son";//�]�l
    if (a == "son_young") return "son_son";//�]�l
}
string son_daughter(string a) {
    if (a == "dad" && g == 0) return "son";//��l
    if (a == "dad" && g == 1) return "son";//��l
    if (a == "mom" && g == 0) return "son_wife";//�@��
    if (a == "mom" && g == 1) return "son_wife";//�@��
    if (a == "bro_old") return "son_son";//�]�l
    if (a == "bro_young") return "son_son";//�]�l
    if (a == "sis_old") return "son_daughter";//�]�k
    if (a == "sis_young") return "son_daughter";//�]�k
}
string son_son(string a) {
    if (a == "dad" && g == 0) return "son";//��l
    if (a == "dad" && g == 1) return "son";//��l
    if (a == "mom" && g == 0) return "son_wife";//�@��
    if (a == "mom" && g == 1) return "son_wife";//�@��
    if (a == "bro_old") return "son_son";//�]�l
    if (a == "bro_young") return "son_son";//�]�l
    if (a == "sis_old") return "son_daughter";//�]�k
    if (a == "sis_young") return "son_daughter";//�]�k
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
    string relationship1 = u8"����";
    string relationship2 = u8"����";
    string relationship3 = u8"�̧�";
    string relationship4 = u8"�n�n";
    string relationship44 = u8"�j�j";
    string relationship5 = u8"�f�f";
    string relationship6 = u8"�V��";
    string relationship7 = u8"�d�l";
    string relationship8 = u8"��l";
    string relationship9 = u8"��l(���~��)";
    string relationship10 = u8"��l(���~��)";
    string relationship11 = u8"�k��";
    string relationship12 = u8"�k��(���~��)";
    string relationship13 = u8"�k��(���~��)";
    string relationship14 = u8"��";
    string relationship15 = u8"��(�k)";
    string relationship16 = u8"��(�k)";
    string relationship17 = u8"����";
    string ss = u8"��";

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
                //cout << "��" << endl;
                relationship[j].push_back("s");
                i += 2;
            }
            if (line[i] == relationship1[0] && line[i+1] == relationship1[1] && line[i+2] == relationship1[2]&& i+5 < line.size()) {
               // cout << "����" << endl;
                relationship[j].push_back("dad");
                i += 5;
            }
            if (line[i] == relationship2[0] && line[i + 1] == relationship2[1] && line[i + 2] == relationship2[2]&& i+5 < line.size()) {
               // cout << "����" << endl;
                relationship[j].push_back("mom");
                i += 5;
            }
            if (line[i] == relationship17[0] && line[i + 1] == relationship17[1] && line[i + 2] == relationship17[2] && i + 5 < line.size()) {
               // cout << "����" << endl;
                relationship[j].push_back("bro_old");
                i += 5;
            }
            if (line[i] == relationship3[0] && line[i + 1] == relationship3[1] && line[i + 2] == relationship3[2]&& i+5 < line.size()) {
                //cout << "�̧�" << endl;
                relationship[j].push_back("bro_young");
                i += 5;
            }
            if (line[i] == relationship4[0] && line[i + 1] == relationship4[1] && line[i + 2] == relationship4[2]&& i+5 < line.size()) {
               // cout << "�n�n" << endl;
                relationship[j].push_back("sis_old");
                i += 5;
            }
            if (line[i] == relationship44[0] && line[i + 1] == relationship44[1] && line[i + 2] == relationship44[2] && i + 5 < line.size()) {
                // cout << "�n�n" << endl;
                relationship[j].push_back("sis_old");
                i += 5;
            }
            if (line[i] == relationship5[0] && line[i + 1] == relationship5[1] && line[i + 2] == relationship5[2]&& i+5 < line.size()) {
                //cout << "�f�f" << endl;
                relationship[j].push_back("sis_young");
                i += 5;
            }
            if (line[i] == relationship6[0] && line[i + 1] == relationship6[1] && line[i + 2] == relationship6[2]&& i+5 < line.size()) {
                //cout << "�V��" << endl;
                relationship[j].push_back("husband");
                i += 5;
            }
            if (line[i] == relationship7[0] && line[i + 1] == relationship7[1] && line[i + 2] == relationship7[2]&& i+5 < line.size()) {
               // cout << "�d�l" << endl;
                relationship[j].push_back("wife");
                i += 5;
            }
            if (line[i] == relationship11[0] && line[i + 1] == relationship11[1] && line[i + 2] == relationship11[2]) {
                if (i + 16 < line.size() && line[i + 6] == relationship9[6]) {
                    i += 13;
                    if (line[i] == relationship12[13] && line[i + 1] == relationship12[14] && line[i + 2] == relationship12[15] && i + 3 < line.size()) {
                       // cout << "�k��(���~��)" << endl;
                        relationship[j].push_back("daughter_old");
                        i += 3;
                    }
                    if (line[i] == relationship13[13] && line[i + 1] == relationship13[14] && line[i + 2] == relationship13[15] && i + 3 < line.size()) {
                        //cout << "�k��(���~��)" << endl;
                        relationship[j].push_back("daughter_young");
                        i += 3;
                    }
                }
                else if (i + 5 < line.size()) {
                    //cout << "�k��" << endl;
                    relationship[j].push_back("daughter");
                    i += 5;
                }
            }
            else if (line[i] == relationship8[0] && line[i + 1] == relationship8[1] && line[i + 2] == relationship8[2]) {
                if (i + 16 < line.size() && line[i + 6] == relationship9[6]) {
                    i += 13;
                    if (line[i] == relationship9[13] && line[i + 1] == relationship9[14] && line[i + 2] == relationship9[15] && i + 3 < line.size()) {
                       // cout << "��l(���~��)" << endl;
                        relationship[j].push_back("son_old");
                        i += 3;
                    }
                    if (line[i] == relationship10[13] && line[i + 1] == relationship10[14] && line[i + 2] == relationship10[15] && i + 3 < line.size()) {
                       // cout << "��l(���~��)" << endl;
                        relationship[j].push_back("son_young");
                        i += 3;
                    }
                }
                else if (i + 5 < line.size()) {
                    //cout << "��l" << endl;
                    relationship[j].push_back("son");
                    i += 5;
                }
            }
            if (line[i] == relationship14[0] && line[i + 1] == relationship14[1] && line[i + 2] == relationship14[2]) {
                if (i + 7 < line.size() && line[i + 3] == relationship15[3]) {
                    i += 4;
                    if (line[i] == relationship15[4] && line[i + 1] == relationship15[5] && line[i + 2] == relationship15[6] && i + 3 < line.size()) {
                        //cout << "��(�k)" << endl;
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
        if (answer(relationship[i]) == "dad_dad")cout << "����";
        if (answer(relationship[i]) == "dad_mom")cout << "����";
        if (answer(relationship[i]) == "dad")cout << "����";
        if (answer(relationship[i]) == "mom")cout << "����";
        if (answer(relationship[i]) == "bro_old")cout << "����";
        if (answer(relationship[i]) == "bro_young")cout << "�̧�";
        if (answer(relationship[i]) == "sis_old")cout << "�n�n";
        if (answer(relationship[i]) == "sis_young")cout << "�f�f";
        if (answer(relationship[i]) == "husband")cout << "��";
        if (answer(relationship[i]) == "wife")cout << "�d";
        if (answer(relationship[i]) == "daughter_old")cout << "�k��";
        if (answer(relationship[i]) == "daughter_young")cout << "�k��";
        if (answer(relationship[i]) == "daughter")cout << "�k��";
        if (answer(relationship[i]) == "son_old")cout << "��l";
        if (answer(relationship[i]) == "son_young")cout << "��l";
        if (answer(relationship[i]) == "son")cout << "��l";
        if (answer(relationship[i]) == "me_female")cout << "�ۤv";////////////////////////////////notice
        if (answer(relationship[i]) == "me_male")cout << "�ۤv";
        if (answer(relationship[i]) == "me")cout << "�ۤv";
        if (answer(relationship[i]) == "dad_bro_old")cout << "�B��";
        if (answer(relationship[i]) == "dad_bro_young")cout << "����";
        if (answer(relationship[i]) == "dad_sis_old")cout << "�h��";
        if (answer(relationship[i]) == "dad_sis_young")cout << "�h��";
        if (answer(relationship[i]) == "dad_bro_old_wife")cout << "�B��";
        if (answer(relationship[i]) == "dad_bro_young_wife")cout << "�T�T";
        if (answer(relationship[i]) == "dad_sis_old_husband")cout << "�h�V";
        if (answer(relationship[i]) == "dad_sis_young_husband")cout << "�h�V";
        if (answer(relationship[i]) == "dad_bro_old_daughter_old")cout << "��n";
        if (answer(relationship[i]) == "dad_bro_old_daughter_young")cout << "��f";
        if (answer(relationship[i]) == "dad_bro_old_son_old")cout << "��S";
        if (answer(relationship[i]) == "dad_bro_old_son_young")cout << "���";
        if (answer(relationship[i]) == "dad_bro_young_daughter_old")cout << "��n";
        if (answer(relationship[i]) == "dad_bro_young_daughter_young")cout << "��f";
        if (answer(relationship[i]) == "dad_bro_young_son_old")cout << "��S";
        if (answer(relationship[i]) == "dad_bro_young_son_young")cout << "���";
        if (answer(relationship[i]) == "dad_sis_old_daughter_old")cout << "��n";
        if (answer(relationship[i]) == "dad_sis_old_daughter_young")cout << "��f";
        if (answer(relationship[i]) == "dad_sis_old_son_old")cout << "��S";
        if (answer(relationship[i]) == "dad_sis_old_son_young")cout << "���";
        if (answer(relationship[i]) == "mom_dad")cout << "�~����";
        if (answer(relationship[i]) == "mom_mom")cout << "�~����";
        if (answer(relationship[i]) == "mom_bro_old")cout << "����";
        if (answer(relationship[i]) == "mom_sis_old")cout << "����";
        if (answer(relationship[i]) == "mom_bro_young")cout << "����";
        if (answer(relationship[i]) == "mom_sis_young")cout << "����";
        if (answer(relationship[i]) == "mom_bro_old_wife")cout << "����";
        if (answer(relationship[i]) == "mom_sis_old_husband")cout << "���V";
        if (answer(relationship[i]) == "mom_bro_old_daughter_old")cout << "��n";
        if (answer(relationship[i]) == "mom_bro_old_daughter_young")cout << "��f";
        if (answer(relationship[i]) == "mom_bro_old_son_old")cout << "��S";
        if (answer(relationship[i]) == "mom_bro_old_son_young")cout << "���";
        if (answer(relationship[i]) == "mom_sis_old_daughter_old")cout << "��n";
        if (answer(relationship[i]) == "mom_sis_old_daughter_young")cout << "��f";
        if (answer(relationship[i]) == "mom_sis_old_son_old")cout << "��S";
        if (answer(relationship[i]) == "mom_sis_old_son_young")cout << "���";
        if (answer(relationship[i]) == "bro_old_wife")cout << "�A�A";
        if (answer(relationship[i]) == "bro_old_daughter")cout << "���k";
        if (answer(relationship[i]) == "bro_old_son")cout << "���l";
        if (answer(relationship[i]) == "bro_young_wife")cout << "�̷@";
        if (answer(relationship[i]) == "bro_young_daughter")cout << "���k";
        if (answer(relationship[i]) == "bro_young_son")cout << "���l";
        if (answer(relationship[i]) == "sis_old_husband")cout << "�n��";
        if (answer(relationship[i]) == "sis_old_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "sis_old_son")cout << "�~�c";
        if (answer(relationship[i]) == "sis_young_husband")cout << "�f��";
        if (answer(relationship[i]) == "sis_young_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "sis_young_son")cout << "�~�c";
        if (answer(relationship[i]) == "husband_dad")cout << "�Ҥ�";
        if (answer(relationship[i]) == "husband_mom")cout << "�ҥ�";
        if (answer(relationship[i]) == "husband_bro_old")cout << "�ҥS";
        if (answer(relationship[i]) == "husband_bro_young")cout << "�ҧ�";
        if (answer(relationship[i]) == "husband_sis_old")cout << "�ҩn";
        if (answer(relationship[i]) == "husband_sis_young")cout << "�ҩf";
        if (answer(relationship[i]) == "husband_bro_old_wife")cout << "�ҥS�A";
        if (answer(relationship[i]) == "husband_bro_young_wife")cout << "�ҧ̷@";
        if (answer(relationship[i]) == "husband_sis_old_husband")cout << "�ҩn��";
        if (answer(relationship[i]) == "husband_sis_young_husband")cout << "�ҩf��";
        if (answer(relationship[i]) == "husband_bro_old_son")cout << "���l";
        if (answer(relationship[i]) == "husband_bro_young_son")cout << "���l";
        if (answer(relationship[i]) == "husband_sis_old_son")cout << "�~�c";
        if (answer(relationship[i]) == "husband_sis_young_son")cout << "�~�c";
        if (answer(relationship[i]) == "husband_bro_old_daughter")cout << "���k";
        if (answer(relationship[i]) == "husband_bro_young_daughter")cout << "���k";
        if (answer(relationship[i]) == "husband_sis_old_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "husband_sis_young_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "wife_dad")cout << "�d��";
        if (answer(relationship[i]) == "wife_mom")cout << "�d��";
        if (answer(relationship[i]) == "wife_bro_old")cout << "�d�S";
        if (answer(relationship[i]) == "wife_bro_young")cout << "�d��";
        if (answer(relationship[i]) == "wife_sis_old")cout << "�d�n";
        if (answer(relationship[i]) == "wife_sis_young")cout << "�d�f";
        if (answer(relationship[i]) == "wife_bro_old_wife")cout << "�d�S�A";
        if (answer(relationship[i]) == "wife_bro_young_wife")cout << "�d�̷@";
        if (answer(relationship[i]) == "wife_sis_old_husband")cout << "�d�n��";
        if (answer(relationship[i]) == "wife_sis_young_husband")cout << "�d�f��";
        if (answer(relationship[i]) == "wife_bro_old_son")cout << "�~�c";
        if (answer(relationship[i]) == "wife_bro_young_son")cout << "�~�c";
        if (answer(relationship[i]) == "wife_sis_old_son")cout << "�~�c";
        if (answer(relationship[i]) == "wife_sis_young_son")cout << "�~�c";
        if (answer(relationship[i]) == "wife_bro_old_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "wife_bro_young_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "wife_sis_old_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "wife_sis_young_daughter")cout << "�~�c�k";
        if (answer(relationship[i]) == "daughter_husband")cout << "�k�B";
        if (answer(relationship[i]) == "daughter_daughter")cout << "�~�]";
        if (answer(relationship[i]) == "daughter_son")cout << "�~�]";
        if (answer(relationship[i]) == "son_wife")cout << "�@��";
        if (answer(relationship[i]) == "son_daughter")cout << "�]�k";
        if (answer(relationship[i]) == "son_son")cout << "�]�l";

        if(i<relationship.size()-1)cout << endl;
    }
	
	
}
