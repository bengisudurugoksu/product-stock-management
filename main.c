#include <stdio.h>
#include <stdlib.h>
int fileoperations(){
FILE *fptr1, *fptr2;
int choice,exit=0,pID,sID,count=0,temp=1,option,index=0,col=0,row=0,cols=5,ch,rows=10,maxlength=8,index=0;
char type,name[50],brand[50],c,feature[50],data[rows][cols][maxlength];
double price;

while(exit==0){
printf("\nPlease select an option to continue:\n  1- Add a new product.\n  2- Delete a product.\n  3- Update a product.\n  4- Add feature to products.\n  5- Add a new stock entry.\n  6- Delete a stock entry.\n  7- Update a stock entry.\n  8- Back to main menu.\n");
scanf("%d", &choice);
switch(choice){
case 1:
printf("Enter the values for the new product(Type,Name,Brand,Price): ");
scanf(" %c %s %s %lf", &type, &name ,&brand, &price);
fptr1 = fopen("product.txt", "a+");
if (fptr1 == NULL)
{	
	printf("Cannot open product.txt\n");w
	exit=1;
}
for (c = getc(fptr1); c != EOF; c = getc(fptr1)){
        if (c == '\n')
            count = count + 1;
}
fprintf(fptr1, "%d,%c,%s,%s,%.2lf", count, type, name, brand, price);   
fclose(fptr1);

break;

case 2:
printf("\nEnter the pID of the product to be deleted:");
scanf("%d", &pID);
void deleteLine(FILE *src, FILE *temp, int line){   
   char buffer[1000];
   int count = 1,pID = 1;
   while ((fgets(buffer, 1000, src)) != NULL){
      if (line != count){
      		if(buffer == '\n'){
      		fprintf(temp, "%d", pID);
      		}
               fputs(buffer, temp);
               pID++;
               
               }
      count++;
   }
}
   fptr1 = fopen("product.txt", "r");
   fptr2 = fopen("temp.txt", "w");
   if (fptr1 == NULL || fptr2 == NULL){
      printf("Unable to open file.");
      exit=1;
   }
   rewind(fptr1);
   deleteLine(fptr1, fptr2, pID);
   fclose(fptr1);
   fclose(fptr2);
   remove("product.txt");
   rename("temp.txt", "product.txt");

break;

case 3:
while ((ch = fgetc(fptr1)) != EOF) {
	if (ch == ',') {
		col++;
	}
	else if (ch == '\n') {
		row++;
		col = 0;
	}
	else {
		data[row][col]= ch;
		}
	}
printf("Please enter the pID of the product to be updated: ");
scanf("%d", &pID);
printf("Please enter the feature to be updated: ");
scanf("%s", &feature);

if(feature == "pID"){
printf("pID can not be changed.");
}

if(feature == "Type"){
fptr1 = fopen("product.txt", "wb");
printf("Enter the new value for that feature: ");
scanf(" %c", &type);
data[pID-1][1]==type;
fwrite(data, sizeof(char), sizeof(data), fptr1);
fclose(fptr1);
} 
break;

case 4:

break;

case 5:

break;

case 6:

break;

case 7:

break;

case 8:
exit=1;
break;
}
}

return 0;
}




int main(){
int choice,exit=0;
while(exit==0){
printf("\nWelcome operator, please select an option to continue:\n  1- File Operations\n  2- Query products\n  3- Check stock status\n  4- Stock control by brand\n  5- Export report\n");
scanf("%d", &choice);
switch(choice){
case 1:
fileoperations();
break;

case 2:

break;

case 3:

break;

case 4:

break;

case 5:
printf("Exporting report.Have a good day!\n");
exit = 1;
}
}


return 0;
}










