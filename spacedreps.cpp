#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SubjectSet{
    private :
    string date;
    int subjects_l;
    string* subjects;
    int counter = 0;

    public :

    SubjectSet(){}

    SubjectSet(string d,int l){
        date = d;
        subjects_l = l;
        subjects = new string[subjects_l];
    }

    ~SubjectSet(){
        delete[] subjects;
    }

    void addSubject(string sub){
        if(counter >= subjects_l)return;
        subjects[counter] = sub;
        counter++;
    }

    void show(){
        cout << date << endl;
        cout << subjects_l << "教科" << endl;
        for(int i = 0;i < subjects_l;i++){
            cout << subjects[i] << ", ";
        }
        cout << "" << endl;
    }

};

int main(){

    SubjectSet data[60];

    fstream file;
    file.open("data.bin", ios::out | ios::in);

    if(!file){
        cout << "データファイルが存在しません。" << endl;
        file.close();
        ofstream newfile("data.bin");
        newfile.close();
        cout << "新しいデータファイルが生成されました。 \n プログラムを再起動してください。" << endl;
    }

    file.close();

   
   int counter = 0; 
    while(true){
        string in;
        cin>>in;
        if(in=="exit")break;

        if(in=="add"){
            string date;
            int l;
            cout << "日付を入力してください" << endl;
            cin >> date;
            cout << "教科数を入力してください" << endl;
            cin >> l;
            SubjectSet newset(date,l);
            for(int i = 0;i < l;i++){
                cout << i <<"番目の教科を入力してください" << endl;
                string sub_in;
                cin>>sub_in;
                newset.addSubject(sub_in);
            }
            data[counter] = newset;
            cout << "学習データが追加されました。" << endl;
	    counter++;
        }

        if(in=="data"){
	        for(int i = 0;i < counter;i++){
            data[i].show();
		}
        }
        if(in=="schedule")cout << "command not available" << endl;


        if(in=="ebbinghaus");

    }

    cout << "closing file..."<< endl;
    cout << "bye bye"<< endl;

    return 0;
}
