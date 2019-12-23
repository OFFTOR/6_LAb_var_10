//ПОдключаем библиотеки к препроцессору
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>//Необходимо для функции sort
using namespace std;
//Прототипы функций
int words_kol(string);
int letter_count(string,int);
int zap_kol(string);
string find_substr(string,int);


//Главная функция
int main(){
  ios::sync_with_stdio(false);

  const string s = "So she was considering in her own mind, as well as she could, for the hot day made her feel very sleepy and stupid, whether the pleasure of making a daisy-chain would be worth the trouble of getting up and picking the daisies, when suddenly a White Rabbit with pink eyes ran close by her.";
  int letters[27]={0};//выделяем память массива и заполняем её нулями

//Считаем кол-во букв
  for(int i = 0;i < s.length();i++){
      letters[int(tolower(s[i])) % 97]++;
 }
  for(int i = 0;i < 26;i++){
      cout << char(i + 97) << " " << letters[i] << endl;

}
//Количество слов
  cout << "Count of word with left and right space : " << words_kol(s) << endl;
 //3)Начало
  vector<string> slovosoch;//Вектор из строк
  vector<int> zap_pos;//Вектор состоящий из позиций первых запятых
  for(int i = 0;i < s.length();i++){
      if(s[i] == ','  || s[i] == '.'){
          zap_pos.push_back(i);
     }
  }
  for(auto i : zap_pos){
      slovosoch.push_back(find_substr(s,i));
  }

  sort(slovosoch.begin(),slovosoch.end());
  cout << "Phrases:";
  for(auto i : slovosoch){
     cout << i << "\n";
    }
   return 0;
   //Конец
}

//Functions:
string find_substr(string s,int l) {
    int left,right;
    bool flag = false;
    for(int i = l;i < s.length();i++){
        if(s[i] == ',' && !flag){
            flag = true;
            left = i + 2;
        }else if((s[i] == ',' || s[i] == '.') && flag){
            right = i;
            return s.substr(left,(right - left));
        }
    }
}


int zap_kol(string s) {
//Функция находит количество запятых в строке
    int count = 0;
    for(auto i : s){
        if(i == ',')count++;
    }
    return count;
}

int words_kol(string s) {
//Функция находит количество слов отделённых пробелами слов слева и справа
  int count = 0;
  bool flag = false;
  for(auto i : s){
      if(i == ' ' && !flag){
          flag = true;
      }
      else if(i == ' ' && flag) {
          count++;
      }else if(i == ',' || i == '.'){
          flag = false;
      }
    }
    return count;
}
