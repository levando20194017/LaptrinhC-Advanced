#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct sinhvien{
	char *hoten;
	int mssv;
	int ngay, thang, nam;
	char gioitinh[10];
};
void nhapds(sinhvien *a,int n){
	fflush(stdin);
	for(int i=0;i<n;i++){
		a[i].hoten= (char *)malloc(100*sizeof(char));
		printf("Sinh vien thu %d: \n" ,i+1);
		printf("Ho ten: ");
		gets(a[i].hoten);
		printf("Nhap ngay, thang, nam sinh: ");
		do{
			scanf("%d%d%d", &a[i].ngay, &a[i].thang, &a[i].nam);
		}while(a[i].ngay>31||a[i].ngay<1||a[i].thang>12||a[i].thang<1||a[i].nam<0&&printf("Vui long nhap lai!"));
		fflush(stdin);
		printf("Ma so sinh vien: ");
		scanf("%d", &a[i].mssv);
		fflush(stdin);
		printf("Gioi tinh: ");
		gets(a[i].gioitinh);
	}
}
void chinhsua(sinhvien *a, int n){
	int swap;
		do{swap=0;
	for(int i=0;i<n;i++){
		//xoa khoang trang dau
		if(a[i].hoten[0]==' '){
		swap=1; 
		for(int j=0;j<strlen(a[i].hoten);j++){
			a[i].hoten[j]=a[i].hoten[j+1];
			}
		}
		else{
		// xoa khoang trang o giua
			for(int j=0;j<strlen(a[i].hoten);j++){
				if(a[i].hoten[j]==' '&&a[i].hoten[j+1]==' '){
					swap=1;
					for(int k=j;k<strlen(a[i].hoten);k++){
			a[i].hoten[k]=a[i].hoten[k+1];
			}
			}
			}
	}
	}
	}while(swap==1);
	for(int i=0;i<n;i++){
		for(int j=strlen(a[i].hoten)-1;j>=0;j--){
			//xoa khoang trang o cuoi
			if(a[i].hoten[j]!=' '){ a[i].hoten[j+1]='\0';
			break;
			}
			}
			}
	// viet hoa danh sach
	for(int i=0;i<n;i++){
		if(a[i].hoten[0]>96||a[i].hoten[0]<122) a[i].hoten[0]=a[i].hoten[0]-32;
		for(int j=1;j<strlen(a[i].hoten);j++){
			if(a[i].hoten[j]==' '){
				if(a[i].hoten[j+1]<122||a[i].hoten[j+1]>96){
					a[i].hoten[j+1]=a[i].hoten[j+1]-32;
					a[i].hoten[strlen(a[i].hoten)]='\0';
					}
				}
		}
	}
	}
void sapxep(sinhvien *a, int n){
	int *s=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
	for(int j=strlen(a[i].hoten)-1;j>=0;j--){
		if(a[i].hoten[j]==' '){
			// tim vi tri ten cua sinh vien
			s[i]=j;
			break;
			}
		}
	}
	int swap;
	int t,h;
	do{
		swap=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1;j++){
				if(strcmp(a[j].hoten+s[j]+1, a[j+1].hoten+s[j+1]+1)>0){
					// neu ten khac nhau
					swap=1;
					sinhvien b= *(a+j);
					*(a+j)=*(a+j+1);
					*(a+j+1)=b;
					h=s[j];
					s[j]=s[j+1];
					s[j+1]=h;
					}
				else{
					if(strcmp(a[j].hoten+s[j]+1, a[j+1].hoten+s[j+1]+1)==0){
						if(strcmp(a[j].hoten,a[j+1].hoten)>0){
							// neu ten giong nhau, dau tien di so sanh ho ten
							swap=1;
							sinhvien b= *(a+j);
							*(a+j)=*(a+j+1);
							*(a+j+1)=b;
							h=s[j];
							s[j]=s[j+1];
							s[j+1]=h;
						}
						else{
							if(strcmp(a[j].hoten,a[j+1].hoten)==0){
							// neu ho ten giong nhau thi so sanh mssv
								if(a[j].mssv>a[j+1].mssv){
									swap=1;
									sinhvien b= *(a+j);
									*(a+j)=*(a+j+1);
									*(a+j+1)=b;
								}
							}
						}
					}
				}
			}
			}
	}while(swap==1);	
	}
void inds(sinhvien *a, int n){
	printf("------------------------\n");
	printf("Ho ten\t\t\tDate of Birth\t\tMSSV\t\tGioi tinh\n");
	for(int i=0;i<n;i++){
		if(strlen(a[i].hoten)<=15)
		printf("%s\t\t%d/%d/%d\t\t%d\t%s\n", a[i].hoten,a[i].ngay,a[i].thang,a[i].nam,a[i].mssv,a[i].gioitinh);
		if(strlen(a[i].hoten)>15)
		printf("%s\t%d/%d/%d\t\t%d\t%s\n", a[i].hoten,a[i].ngay,a[i].thang,a[i].nam,a[i].mssv,a[i].gioitinh);
		}
	}
int main(){
	printf("Le Van Do 20194017\n");
	int n;
	printf("Nhap so sinh vien: ");
	scanf("%d",&n);
	sinhvien* a= (sinhvien*)malloc(n*sizeof(sinhvien));
	nhapds(a,n);
	chinhsua(a,n);
	sapxep(a,n);
	inds(a,n);
	for(int i=0;i<n;i++){
	free(a[i].hoten);
		}
	free(a);
	return 0;
}
