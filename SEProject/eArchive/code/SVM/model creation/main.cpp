// model creation


#include "svm.h"
#include <string.h>
#include <string>
#include<iostream>
#include <vector>
#include <fstream>

using namespace std;


svm_parameter param;

void init_param(){
	param.svm_type = C_SVC;
	param.kernel_type = RBF;
	param.degree = 3;
	param.gamma = 0.0001;
	param.coef0 = 0;
	param.nu = 0.5;
	param.cache_size = 100;
	param.C = 10;
	param.eps = 1e-5;
	param.shrinking = 1;
	param.probability = 0;
	param.nr_weight = 0;
	param.weight_label = NULL;
	param.weight = NULL;
}

std::vector<std::string> split(std::string str,std::string cha) 
{   
	int size = (int) str.size();
    std::string::size_type pos;
    std::vector<std::string> result;
   // str=str+cha;  
    
    for(int i=0; i<size; i++)
    {
        pos=str.find(cha,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i = pos+cha.size() - 1;
        }
    }
    return result;
}

int CountLines(char *filename)//count the line of file
{
ifstream ReadFile;
int n=0;
string temp;
ReadFile.open(filename,ios::in);//ios::in 表示以只读的方式读取文件
if(ReadFile.fail())//文件打开失败:返回0
{
   return 0;
}
else//文件存在,返回文件行数
{
   while(getline(ReadFile,temp))
   {
    n++;
   }
   return n;
}
ReadFile.close();
}


int main(){

	//vector<vector<double> > Mt1;
	double   tmpValue;   
	init_param();
	ifstream file;
    int LINES,i=0,j=0;

	
	LINES=CountLines("Trainning_weight.txt");
	ifstream myfile1 ("Trainning_weight.txt");
    string line1;
    

	 vector<vector<string>> result ;
	 int det[300]={0} ;
	for (i = 0; i < LINES; i++ )  //LINE 是样本数量
           {
              result.push_back ( vector<string>() );  
			 
            }
	while (getline(myfile1, line1) ) 
		{  
		   
			 vector<string> tmp;
			 tmp = split(line1, "\t");
			 if (line1!="")
			 {
			  for (i=1;i<=15;i++)    //2是 feature number，到时要改掉的, i 从1 开始，因为第一个是判断值 ：0 or 1
         	  { 
		         result[j].push_back(tmp[i]);	
				 
			 	//= split(line1, "\t");    
			  }	
			  det[j]=atoi(tmp[0].c_str());
			  j++;
			  if (j==LINES)  break;
			 }

        }

    myfile1.close();



	svm_problem prob;
	//prob.l = 2; //样本数
	prob.l=300;
	prob.y = new double[prob.l];
	//double d;
	int probfeature = 15; //样本特征维数

	if(param.gamma == 0) param.gamma = 0.5;
	svm_node *x_space = new svm_node[(probfeature+1)*prob.l];//样本特征存储空间
	prob.x = new svm_node * [prob.l]; //每一个X指向一个样本
	//cout<<"size: "<<sizeof(x_space)<<endl;
	//train data 身高190cm,体重70kg，男
	///*
	for (i=0;i<300;i++)
	{
	   for (j=0;j<probfeature;j++)
	   { 
		   if (i==0)
		   {
	        x_space[j].index = j+1; 
		    tmpValue=   atof(const_cast<const char *>(result[i][j].c_str())); // string to char to double
	        x_space[j].value = tmpValue; 
		   }else 
		   {
		     x_space[(probfeature+1)*i+j].index = j+1; 
		     tmpValue=   atof(const_cast<const char *>(result[i][j].c_str())); // string to char to double
	         x_space[(probfeature+1)*i+j].value = tmpValue; 
		   
		   }
	   } // end j	
	  
	   if (i==0){
		   
	       x_space[j].index = -1;
		   prob.x[i] = &x_space[0] ;
	   }
	   else {
		   
	        x_space[(probfeature+1)*i+j].index = -1;
			prob.x[i] = &x_space[(probfeature+1)*i];
	     }	   
		  /* prob.y[0] = 1;
		   prob.y[1] = 1;
		    prob.y[2] = 1;
		    prob.y[3] = 1;
		   prob.y[4] = 1;
		    prob.y[5] = 1;
		   prob.y[6] = 1;
		    prob.y[7] = -1;
		   prob.y[8] = -1;
		    prob.y[9] = -1;
		   prob.y[10] = -1;
		    prob.y[11] = -1;
		   prob.y[12] = -1;
		    prob.y[13] = -1;
		   prob.y[14] = 1;
		    prob.y[15] = 1;
		   prob.y[16] = 1;
		    prob.y[17] = 1;
		   prob.y[18] = 1;
		    prob.y[19] = 1;
		   prob.y[20] = -1;
		    prob.y[21] = -1;
		   prob.y[22] = -1;
		    prob.y[23] = -1;
			 prob.y[24] = -1;*/
	}//end i
	for (i=0;i<300;i++)
	{
	  prob.y[i] = det[i];
	
	}
	//*/
	/*
	x_space[0].index = 1;
	x_space[0].value = 0.9;
	x_space[1].index = 2;
	x_space[1].value = 23;
	x_space[2].index = -1;
	prob.x[0] = &x_space[0];
	prob.y[0] = 1;
	x_space[3].index = 1;
	x_space[3].value = 0;
	x_space[4].index = 2;
	x_space[4].value = 12;
	x_space[5].index = -1;
	prob.x[1] = &x_space[3];
	prob.y[1] = -1;
	x_space[6].index = 1;
	x_space[6].value = 22;
	x_space[7].index = 2;
	x_space[7].value = 1.2;
	x_space[8].index = -1;
	prob.x[2] = &x_space[6];
	prob.y[2] = -1;
	x_space[9].index = 1;
	x_space[9].value = 3;
	x_space[10].index = 2;
	x_space[10].value = 0.2;
	x_space[11].index = -1;
	prob.x[3] = &x_space[9];
	prob.y[3] = -1;
	//*/


	svm_model *model = svm_train(&prob, &param);
	svm_save_model("modle.txt", model);



	delete[] x_space;
	delete[] prob.x;
	delete[] prob.y;
}