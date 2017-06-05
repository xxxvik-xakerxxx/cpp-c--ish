#include <iostream>
using namespace std;
#pragma argsused
#include <string.h>
int main(){
int i,j,len,first=0,second=0;
string alpha[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
string cipher[3],drive[10],f_font,s_font,t_font;
string key[10];
cout<<"Alphabets:\n";
for(i=0;i<26;i++){
cout<<alpha[i]<<"-";
cout<<i;
cout<<" ";
if(i==11 || i==21){
cout<<endl;
}
}
cout<<endl<<"Enter the word to cipher 'lenght 3 font':"<<endl;
for(i=0;i<3;i++){
cin>>cipher[i];
cout<<cipher[i];
}
cout<<endl<<"Enter lenght of key word:"<<endl;
cin>>len;
cout<<len;
cout<<endl<<"Enter the key word:"<<endl;;
for(i=0;i<len;i++){
cin>>key[i];
cout<<key[i];
}
cout<<endl;
for(i=0;i<len;i++){
    for(j=0;j<3;j++){
        cout<<cipher[j]<<" ";
        second+=1;
        if(second==len){
            first=1;
            break;
        }
    }
     if(first==1){
            break;
        }
}
    cout<<endl;
for(i=0;i<len;i++){
    cout<<key[i]<<" ";
}
cout<<endl;
/*Position of cipher */
f_font=cipher[0];
int f_pos=0,s_pos=0,t_pos=0;
s_font=cipher[1];
t_font=cipher[2];
for(i=0;i<26;i++){
    if(alpha[i]==f_font){
        f_pos=i;
    }
    if(alpha[i]==s_font){
        s_pos=i;
    }
     if(alpha[i]==t_font){
        t_pos=i;
    }
}
/*Position of key_word*/
int pos[10],*ad,val=0,tr=0;
for(i=0;i<len;i++){
    key[i];
    cipher[i];
    for(j=0;j<26;j++){
           ad=0;
        if(key[i]==alpha[j]){
           ad=&j;
           pos[i]=*ad;
        }
    }
}
second=0;
first=0;
/*Make a cipher*/
int dr=0,f=0,s=0,t=0,pos_k[10],*dres;
for(i=0;i<len;i++){
       for(j=0;j<3;j++){
           dr=pos[j];
           if(i!=0){
               dr=pos[j+3];
           }
           if(cipher[j]==f_font){
               f=abs(dr-f_pos);
               cout<<alpha[f]<<" ";
           }
           if(cipher[j]==s_font){
              s=abs(dr-s_pos);
               cout<<alpha[s]<<" ";
           }
           if(cipher[j]==t_font){
               t=abs(dr-t_pos);
               cout<<alpha[t]<<" ";
           }
           second+=1;
           if(second==len){
                first=1;
                break;
           }
       }
       if(first==1){
            break;
        }
}
return 0;
}
