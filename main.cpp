
// we have done our project by using singly linked list !!!
#include<iostream>
#include<fstream>
#include<list>
#include<iterator>
using namespace std ;
void Register_students();
void Register_courses();
void Register_student_for_course();
void Sort_student_by_name();
void Display_details_students();
void display_registredcourse();
void Delete_student_id();
void Delete_course_courseNo();
void enter_mark();
void read_course_file();
void menu();
void manege_all_function();// this function call all function declared in this project ;
// structure defnition of singly linked list



struct course{
    int courseNo;
    string course_title ;
     int   crh;
     course *next;
};



struct studentcourse {
 int courseNo;
    string course_title ;
     int crh;
     char  grd;
     int gradeass=0;
     studentcourse  *next;
};


struct student {
 string id ;
 string first_name ;
 string father_name ;
 int age ;
 int number_of_course=0;
 string sex ;
 course addc;
 studentcourse * sthead=NULL;
student * next ;
};



student * accept_New_Student();
student * Searches_student_by_id(string id );
course  * accept_New_course();
course * Searche_course_by_course_number(int courseNo);
studentcourse * Searche_course_by_course_number(studentcourse * sthead1 ,int courseNo);
student* SortedMerge(student* a, student* b);
void FrontBackSplit(student* source,
                    student** frontRef, student** backRef);
student *head =NULL;
course *crshead=NULL;
course *crsheadf=NULL;



int main (){

    cout<<"\n\n\t\t\t\t\tSTUDENT RECORD MANAGMENT SYSTEM \n\n \n";
manege_all_function();
return 0;
}



student * accept_New_Student(){
    system("Color 0B");
fstream file;
file.open("student.txt",ios::app);
student * temp =new student ;
string fname , father_name ;
int age ;
string sex ;


cout <<"\t\t\tEnter the name of the student \n";
cout<<"\t\t\t";
cin>>fname ;
temp->first_name=fname ;



cout <<"\t\t\tEnter the father's name  of  the student \n";
cout<<"\t\t\t";
cin>>father_name;
temp->father_name=father_name ;


cout <<"\t\t\tEnter the id of the student \n";
int correct=0;
while (correct<1){
    string id;
cout<<"\t\t\t";
cin>>id;
student * temp1 =Searches_student_by_id(id );
if(temp1==NULL){
    correct++;
temp->id=id;
}
else
    cout <<"student with this id already exist, try again\n";
}



cout<<"\t\t\tEnter the sex of the student \n";
cout<<"\t\t\t";
cin>>sex;
temp->sex=sex;


cout<<"\t\t\tEnter the age of the student \n";
cout<<"\t\t\t";
cin>>age ;

temp->age=age;
temp->next=NULL;
file<<fname<<"\n";
file<<father_name<<"\n";
file<<temp->id<<"\n";
file<<sex<<"\n";
file<<age<<"\n";


return temp;

}



course  * accept_New_course()
{
    system("Color 0");
    fstream file2;
file2.open("course.txt",ios::app);

course * temp =new  course  ;
string courseTitle ;
int crh,courseNo ;


cout <<"\t\t\tEnter the title of the course  \n";
cout<<"\t\t\t";
   cin>>courseTitle ;
temp->course_title=courseTitle ;



cout <<"\t\t\tEnter the course number of the course  \n";
int correct=0;
while (correct<1){
    int courseNo;
cout<<"\t\t\t";
cin>>courseNo;
course * temp1 = Searche_course_by_course_number(courseNo);
if(temp1==NULL){
    correct++;
temp->courseNo=courseNo ;
}
else
    cout <<"Course with this course number already exist, try again\n";
}

cout <<"\t\t\tEnter the the credite houre of the course  \n";
cout<<"\t\t\t";
cin>>crh;
temp->crh=crh;


temp->next=NULL;


file2<<temp->courseNo<<"\n";
file2<<temp->course_title<<"\n";
file2<<temp->crh<<"\n";

return temp;

}




void Register_students(){
system("Color D");
student *temp=accept_New_Student();
if (head ==NULL)
    head =temp;
else {
    student *temp1=head ;
    while(temp1->next!=NULL)
        temp1=temp1->next;

    temp1->next=temp;
}
}



void Register_courses(){

course *temp=accept_New_course();
if (crshead ==NULL)
    crshead =temp;
else {
    course  *temp1=crshead ;
    while(temp1->next!=NULL)
        temp1=temp1->next;

    temp1->next=temp;
}
}


void Register_student_for_course(){
    system("Color 0F");
    int courseNo;
    string id ;
    studentcourse * temp2=new studentcourse;
 cout <<"\t\t\t\tEnter the id of student you want to register for course \n";
 cout<<"\t\t\t\t";
 cin>>id ;
 cout <<"\t\t\t\tenter the course number \n";
 cout<<"\t\t\t\t";
 cin>>courseNo;
 course * temp=Searche_course_by_course_number(courseNo);
 student * temp1=Searches_student_by_id( id);
 if (temp1!=NULL && temp!=NULL)
 {

   temp2->courseNo=temp->courseNo  ;
   temp2->course_title=temp->course_title  ;
   temp2->crh=temp->crh  ;
   temp2->next=NULL;
   temp1->number_of_course=temp1->number_of_course+1;
   if (temp1->sthead==NULL)
    temp1->sthead=temp2;
   else {
       studentcourse *temp3= temp1->sthead;
    while (temp3->next!=NULL)
    temp3=temp3->next;
    temp3->next=temp2;

   }


 }
 else if(temp==NULL && temp1!=NULL)
        cout<<"\t\t\t\tThere is no registerd course with course number :"<<courseNo<<endl;
   else if(temp1==NULL && temp!=NULL)
        cout<<"\t\t\t\tThere is no student  with id :"<<id<<endl;
        else
            cout<<"\t\t\t\tYou have enterd id and course number which is not registerd \n";
}




void enter_mark(){
    system("Color A");
    int mid ,fina1,courseNo;
    string id ;
    char grade;
    cout <<"\t\t\t\tEnter the id of the student\n";
    cout<<"\t\t\t\t";
    cin >>id;
    cout<<"\t\t\t\tEnter the course number \n";
    cout<<"\t\t\t\t";
    cin>>courseNo;
    cout <<"\t\t\t\tEnter the midterm result of the student \n";
    cout<<"\t\t\t\t";
    cin>>mid;
    cout <<"\t\t\t\tEnter the final result of the student \n";
    cout<<"\t\t\t\t";
    cin>>fina1;
    int total =mid + fina1;
    if (total>=83)
        grade='A';
        else if(total>=75)
           grade='B';
         else if(total>=65)
           grade='C';
            else if(total>=40)
           grade='D';
            else if(total<=39)
           grade='F';
     course * temp=Searche_course_by_course_number(courseNo);
     student * temp1=Searches_student_by_id( id);

      if (temp1!=NULL && temp!=NULL)
 {
        studentcourse * temp2=Searche_course_by_course_number(temp1->sthead , courseNo);
        if (temp2==NULL)
            cout <<"\t\t\t\tThis  student is not registerd for  the course with course number : "<<courseNo<<endl;
        else{
            temp2->gradeass=temp2->gradeass+1;
            temp2->grd=grade;
        }

 }
 else if(temp==NULL && temp1!=NULL)
        cout<<"\t\t\t\tThere is no registerd course with course number :"<<courseNo<<endl;
   else if(temp1==NULL && temp!=NULL)
        cout<<"\t\t\t\tThere is no student  with id :"<<id<<endl;
        else
            cout<<"\t\t\t\tYou have enterd id and course number which is not registerd \n";
}




student * Searches_student_by_id(string id){

    if (head ==NULL)
    {
       return head;

    }
    else {

student * temp=head ;
while (temp!=NULL){
if(temp->id==id){
    return  temp;
}
  temp=temp->next;
}
    return temp;
    }
}



course * Searche_course_by_course_number(int courseNo){

     if (crshead ==NULL)
    {
       return crshead;

    }
    else {

course  * temp=crshead ;
while (temp!=NULL){
if(temp->courseNo==courseNo){
    return  temp;
}
  temp=temp->next;
}
return temp;
    }
}




studentcourse * Searche_course_by_course_number(studentcourse * sthead1 ,int courseNo){

    if (sthead1 ==NULL)
    {
       return sthead1;

    }
    else {

studentcourse * temp=sthead1 ;
while (temp!=NULL){
if(temp->courseNo==courseNo){
    return  temp;
}
  temp=temp->next;
}
return temp;
    }
}

void Display_details_students(){
 fstream file3;
file3.open("studentCourse.txt",ios::app);
        system("Color 9E");
    student * temp=head ;
    if (temp==NULL)
        cout <<"\t\t\t\tthe list is empty\n";
    else {
            int c=1;
        while (temp!=NULL)
        {
              cout <<"\n==============================================\n";
              file3<<"\n==============================================\n";
            if (c==1){
            cout <<"======detaile of the "<<c<<"st student ======\n";
            file3 <<"======detaile of the "<<c<<"st student ======\n";
            }

            else if (c==2){
                cout <<"======detaile of the  "<<c<<"nd student ======\n";
                file3 <<"======detaile of the  "<<c<<"nd student ======\n";
            }
             else if (c==3){
                cout <<"======detaile of the  "<<c<<"nd student ======\n";
                 file3 <<"======detaile of the  "<<c<<"nd student ======\n";
             }
                 else{
                cout <<"======detaile of the "<<c<<"th student ======\n";
                file3<<"======detaile of the "<<c<<"th student ======\n";
                 }
                cout <<"==============================================\n\n";
                file3 <<"==============================================\n\n";
                cout <<"\n#########Personal information #########\n";
                 file3 <<"\n#########Personal information #########\n";
    cout <<"\n\n Student's name "<<temp->first_name;
    cout <<"\n\n Student father's name "<<temp->father_name;
    cout <<"\n\n Student's id "<<temp->id;
    cout <<"\n\n Student's sex "<<temp->sex;
    cout <<"\n\n Student's age "<<temp->age<<endl;
    file3 <<"\n\n Student's name "<<temp->first_name;
    file3 <<"\n\n Student father's name "<<temp->father_name;
    file3 <<"\n\n Student's id "<<temp->id;
    file3 <<"\n\n Student's sex "<<temp->sex;
    file3 <<"\n\n Student's age "<<temp->age<<endl;
    if(temp->number_of_course==0){
        cout<<"This student is not registrd for course yet\n";
       file3<<"This student is not registrd for course yet\n";
    }
    else {
       studentcourse * temp3=temp->sthead;
     cout <<"\n######## Registerd for courses with  ########\n";
     file3<<"\n######## Registerd for courses with  ########\n";
    while (temp3!=NULL){

    cout <<"\n\n course number "<<temp3->courseNo;
    cout <<"\n\n course  title "<<temp3->course_title;
    cout <<"\n\n credit houre    "<<temp3->crh<<endl;
    file3<<"\n\n course number "<<temp3->courseNo;
    file3 <<"\n\n course  title "<<temp3->course_title;
    file3 <<"\n\n credit houre    "<<temp3->crh<<endl;
    file3<<endl;
    cout<<endl;
    if(temp3->gradeass==0){
        cout<<"Grade for this course is not reported yet \n";
        file3<<"Grade for this course is not reported yet \n";
    }
    else{
    cout <<"\n\n grade   "<<temp3->grd;
    cout<<endl;
    file3 <<"\n\n grade   "<<temp3->grd;
    file3<<endl;
    }
   temp3=temp3->next;
    }

    }
    temp=temp->next;
    c++;
        }
    }


    }


void display_registredcourse(){
      system("Color 9F");
      fstream file;
file.open("Detaile of student.txt",ios::app);
      course  * temp=crshead ;
    if (temp==NULL)
        cout <<"\t\t\t\tthe list is empty\n";
    else {
            int c=1;
        while (temp!=NULL)
        {
            if (c==1){
            cout <<"======detaile of the "<<c<<"st course ======\n";
             file<<"======detaile of the "<<c<<"st course ======\n";
            }
            else if (c==2){
                cout <<"======detaile of the  "<<c<<"nd course ======\n";
                file<<"======detaile of the "<<c<<"nd course ======\n";
               }
             else if (c==3)
                cout <<"======detaile of the "<<c<<"rd course ======\n";
                 else
                cout <<"======detaile of the "<<c<<"th course ======\n";
    cout <<"\n\n course number "<<temp->courseNo;
    cout <<"\n\n course  title "<<temp->course_title;
    cout <<"\n\n credit houre    "<<temp->crh;
    cout<<endl;
    temp=temp->next;
    c++;
        }
    }
  }





  void Delete_student_id(){

   if (head ==NULL)
    cout <<"\t\t\t\t the list is empty \n";

   else
   {
       string id ;
       int c=0;
       cout <<"\t\t\t\t Enter the id of the student you want to delete \n";
       cout<<"\t\t\t\t";
       cin>>id ;
       if(id==head->id){
       student * temp=head ;
       head =head->next;
       cout<<"\t\t\t\tRecored deleted successfuly\n";
       delete temp;
   }
       else
       {
        student * temp1=head ;
        student * temp2=head->next;
        while(temp2!=NULL){
            if(id==temp2->id)
            {
               temp1->next=temp2->next;
              cout<<"\t\t\t\tRecored deleted successfuly\n";
              c++;
              delete temp2;
              break;
            }
            temp1=temp2;
            temp2=temp2->next;
        }

       }
       if(c==0)
        cout <<"\t\t\t\tStudent with this id is not added to recored \n";

  }
  }


  void Delete_course_courseNo()
  {



   if (crshead ==NULL)
    cout <<" \t\t\t\tthe list is empty \n";

   else
   {
      int courseNo ;
       int c=0;
       cout <<" \t\t\t\tEnter the course number of the you want to delete \n";
       cout<<"\t\t\t\t";
       cin>>courseNo ;
       if(courseNo==crshead->courseNo){
       course * temp=crshead ;
       crshead =crshead->next;
       cout<<"\t\t\t\tRecored deleted successfuly\n";
       delete temp;
   }
       else
       {
         course * temp1=crshead ;
         course * temp2=crshead->next;
        while(temp2!=NULL){
            if(courseNo==temp2->courseNo)
            {
               temp1->next=temp2->next;
              cout<<"\t\t\t\tRecored deleted successfuly\n";
              c++;
              delete temp2;
              break;
            }
            temp1=temp2;
            temp2=temp2->next;
        }

       }
       if(c==0)
        cout <<"\t\t\t\tStudent with this id is not added to recored \n";

  }
  }




   void sortstudent(student** headRef)
{
    student* head = *headRef;
    student* a;
    student* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    sortstudent(&a);
    sortstudent(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
student* SortedMerge(student* a, student* b)
{
    student* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);


/* Pick either a or b, and recur */
    if (a->first_name<= b->first_name) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
void FrontBackSplit(student* source,
                    student** frontRef, student** backRef)
{
    student* fast;
    student* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}


void read_course_file(){
ifstream readfile;
readfile.open("course.txt",ios::app);

  if(readfile.fail())
    {
        cout<<"\t\t\t\tTHE FILE COULD NOT BE OPENED";
        cin.ignore();
        cin.get();
    }
    else {

    while(!readfile.eof())
    {
        course  * temp=new course ;

        readfile>>temp->courseNo>>temp->course_title>>temp->crh;
        temp->next=NULL;

        if(crsheadf==NULL)
         crsheadf=temp;
        else {
            course * temp1=crsheadf;
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->next=temp;
        }
    }

        course * temp2=crsheadf;
        if(temp2==NULL)
            cout<<"\t\t\t\tNO RECORD FOUND"<<endl<<endl;
        else {
                while (temp2!=NULL){
        cout<<"\t\t\t\tCOURSE NUMBER :"<<temp2->courseNo<<endl<<endl;
        cout<<"\t\t\t\tCOURSE TITLE/"<<temp2->course_title<<endl<<endl;
        cout<<"\t\t\t\tCREDIT HOURS:"<<temp2->crh<<endl<<endl;
        cout<<"=================================================================================="<<endl;
                }
        }

readfile.close();
    }
}



void read_student_file(){
ifstream readfile;
readfile.open("student.txt",ios::app);
student  * temp=head;
bool flag =false;
  if(readfile.fail())
    {
        cout<<"\t\t\t\tTHE FILE COULD NOT BE OPENED";
        cin.ignore();
        cin.get();
    }

    while(!readfile.eof())
    {
       for(temp=head;temp!=NULL;temp=temp->next){
        readfile>>temp->first_name>>temp->father_name>>temp->id>>temp->sex>>temp->age;
        cout<<"\t\t\t\tSTUDENT NAME :"<<temp->first_name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT FATHER'S NAME/"<<temp->father_name<<endl<<endl;
        cout<<"\t\t\t\tDTUSENT'S ID :"<<temp->id<<endl<<endl;
        cout<<"\t\t\t\t SEX /"<<temp->sex<<endl<<endl;
        cout<<"\t\t\t\tAGE:"<<temp->age<<endl<<endl;
        cout<<"=================================================================================="<<endl;
       flag=true;
        }
}
readfile.close();
    if(flag==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cin.ignore();
    cin.get();
}



/*void displayStudentsRecord() {
   ifstream filestd;
  filestd.open("student.txt", ios::binary | ios::in);
  while (!filestd.eof() && filestd.read((char*)&student, sizeof(Student))) {
    stlist->push_back(*student);
    student = student->next;
  }
  filestd.close();
  list<Student>::iterator i;

  for (i = stlist->begin(); i != stlist->end(); i++) {

    cout << i-> << endl;
    cout << i->lname << endl;
    cout << i->deprt << endl;
    cout << i->batch << endl;
    cout << i->id << endl;
    cout << i->age << endl;
    cout << i->gender << endl;
  }

}*/

void menu(){


cout <<"\t\tPRESS\n";
     cout <<"\t\t1   To register new student\t\t\t8  To delete course \n";
     cout <<"\t\t2   To register new course\t\t\t9  To sort students by name \n";
     cout <<"\t\t3   To register student for course\t\t10   To clear console \n";
    cout <<"\t\t4   To search student\t\t\t\t11  display detaile of courses \n";
    cout <<"\t\t5   To search course\t\t\t\t12  to enter mark \n";
     cout <<"\t\t6   To display details of all students\t\t13  To read student's file   \n";
      cout <<"\t\t7   To delete student\t\t\t\t14  To read courses from file   \n";


}



void manege_all_function(){
system("Color 0A");
int choice ;
menu();
cout<<"\t\t\tEnter your choice \n";
cout<<"\t\t\t";
cin>>choice ;
while (true ){
    switch(choice)
    {
    case 1:
        Register_students();
        break;
    case 2:
        Register_courses();
        break;
    case 3:
        Register_student_for_course();
        break;
    case 4:
        {
       string id;
       cout<<"\t\t\t\tEnter the id of the student you want to search \n";
       cout<<"\t\t\t\t";
       cin>>id ;
        student * temp=Searches_student_by_id(id);
        if(temp!=NULL){
    cout <<"\n\n \t\t\t\tStudent's name "<<temp->first_name;
    cout <<"\n\n \t\t\t\tStudent father's name "<<temp->father_name;
    cout <<"\n\n\t\t\t\t Student's id "<<temp->id;
    cout <<"\n\n\t\t\t\t Student's sex "<<temp->sex;
    cout <<"\n\n \t\t\t\tStudent's age "<<temp->age<<endl;
        }
        else
         cout<< "\t\t\t\tThere is no student with such id number in the list  or the list is empty\n";
       break;
        }
      case 5:
        {
            int  courseNo;
       cout<<"\t\t\t\tEnter the course number of the course you want to search \n";
       cout<<"\t\t\t\t";
       cin>>courseNo ;
        course * temp=Searche_course_by_course_number(courseNo );
        if(temp!=NULL){
    cout <<"\n\n\t\t\t\t course  number "<<temp->courseNo;
    cout <<"\n\n\t\t\t\t  course title  "<<temp->course_title;
    cout <<"\n\n\t\t\t\t course credit houre "<<temp->crh;
    cout<<endl;
        }
        else
         cout<< "\t\t\t\tThere is no course  with such id number in the list  or the list is empty\n";
       break;
        }
        case 6:
        Display_details_students();
        break;
    case 7:
        Delete_student_id();
        break;
    case 8:
        Delete_course_courseNo();
        break;
    case 9:
       sortstudent(&head);
        break;

    case 10:
       system("cls");
       break;
    case 11:
        display_registredcourse();
        break;
    case 12:
        enter_mark();
        break;

    case 13 :
       // read_student_file();
        break;

    case 14 :
       // read_course_file();
        break;



    case 0:
        cout<<"\t\t\tThanks for using \n";
        exit(0);
    default :
        cout <<"\t\t\tYou have enter wrong choice please try again \n";

    }
    menu();
cout<<"\t\t\tEnter your choice \n";
cout<<"\t\t\t";
cin>>choice ;
}


}
