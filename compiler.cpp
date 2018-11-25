#include<bits/stdc++.h>
using namespace std;
ifstream in("", ios::in);//origin file
ifstream cfg("g3s.cfg", ios::in);//configuration file
string fname,gcc_path,mode;
bool flag;
long long loopheight;
void inline get_gcc_path(){
	cout<<"config not found or g++ path not found in config!!!\ng++ path:";
	getline(cin,gcc_path);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cout<<"g3s compiler 1.0(v20181124)\ncompile filename:";
	cin>>fname;
	in.open(fname.c_str());
	while(!in.is_open()){
		cout<<"File non exist!!!\nDid you enter a valid filename with a file???\ncompile filename:";
		cin>>fname;
		in.open(fname.c_str(),ios::in);
	}
	cout<<"Started compiling:"<<fname<<">>";
	for(int i=0;i<fname.length()-3;i++)cout<<fname[i];
	cout<<"exe"<<endl;
	cout<<"Parsing:"<<fname<<endl;
	if(cfg.is_open()&&!cfg.eof()){
		while(gcc_path=="")getline(cfg,gcc_path);
		flag=true;
		if(!cfg.eof())while(mode=="")getline(cfg,mode);
	}
	if(!flag){
		get_gcc_path();
	}
	cfg.close();
	ofstream cfg("g3s.cfg", ios::out);
	cfg<<gcc_path;
	cfg.close();
	convert_g3s_cpp();//TODO
	call_gcc();//TODO
	return 0;
}
