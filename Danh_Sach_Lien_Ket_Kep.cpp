#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *next,*prev;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}DList;
/////////////////////////////////////
void initList(DList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(DList L)
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(DList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->next = NULL;
    	pp->prev = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pHead->prev=pp;
    		pp->next=L->pHead;
    		L->pHead=pp;
    		}
    	L->spt++;
    }
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(DList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in d? li?u trong node 
        	pp = pp->next;
    	}
}
/////////////////////////////////////////
void insert_Tail(DList*L,Data x){
	Node *pp;
	pp=(Node*) malloc(sizeof(Node));
	pp->infor =x;
	pp->next=NULL;
	pp->prev=NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		L->pTail->next=pp;
		pp->prev=L->pTail;
		L->pTail=pp;
	}
	L->spt++;
}
void insert_After(DList *L,Node *q,Data x){
	Node *pp;
	if(NULL==q) return;
	else{
		pp=(Node*) malloc(sizeof(Node));
		pp->infor=x;
		pp->next=q->next;
		q->next->prev=pp;
		pp->prev=q;
		if(q==L->pTail)L->pTail=pp;
		L->spt++;
	}
}
void xoa_dau(DList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp=L->pHead;
		L->pHead=pp->next;
		free(pp);
		L->spt--;
		if(L->pHead==NULL)L->pTail=NULL;
	}
}
void xoa_cuoi(LList *L,Node *q){
	Node *pp;
	if(NULL==q) return;
	else{
		pp=q->link;
		if(q->link==L->pTail)
		L->pTail=q;
		q->link=pp->link;
		free(pp);
		L->spt--;
	}
}
void tach(LList L,LList *L1,LList *L2){
	initList(L1);
	initList(L2);
	Node *pp=L.pHead;
	while(pp!=NULL){
		if(pp->infor.d1<5.00||pp->infor.d2<5.00||pp->infor.d3<5.00){
			insert_Head(L1,pp->infor);
		}else{
			insert_Head(L2, pp->infor);
		}pp=pp->link;
	}
}
void ghep(LList *L,LList L1,LList L2){
	initList(L);
	Node *p1=L1.pHead;
	Node *p2=L2.pHead;
	if(L1.spt<L2.spt){
		while(p1!=NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1=p1->link;
			p2=p2->link;
		}
		while(p2!=NULL){
			insert_Head(L, p2->infor);
			p2=p2->link;
		}
	}
	else{
		while(p2!=NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1=p1->link;
			p2=p2->link;
		}
		while(p1!=NULL){
			insert_Head(L, p1->infor);
			p1=p1->link;
		}
	}
}
void del_Head(LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp=L->pHead;
		L->pHead=pp->link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL) L->pTail=NULL;
	}
}
void del_After(LList *L,Node *q){
	Node *pp;
	if(NULL==q) return;
	else{
		pp=q->link;
		if(q->link==L->pTail){
		   L->pTail=q;
		   q->link=pp->link;
		   free(pp);
		   L->spt--;
	    }
	}
}
Node* tim (LList L,int ma){
	Node *q=L.pHead;
	while(q!=NULL&&q->infor.masv!= ma)
	     q=q->link;
	     return q;
}
void del_K(LList *L,char K[30]){
	Node *pp=L->pHead,*q;
	while(pp!=NULL&&!strstr(pp->infor.hoten,K)){
		q=pp;
		pp=pp->link;
	}
	if(NULL==pp) return;
	else{
		if(pp==L->pHead) del_Head(L);
		else del_After(L,q);
	}
}
void chen_tang(LList *L,Data x){
	Node *pp=L->pHead,*q;
	while(pp!=NULL && pp->infor.masv<x.masv){
		q=pp;
		pp=pp->link;
	}
	if(pp==L->pHead) insert_Head(L,x);
	else insert_After(L,q,x);
}
int main(){
    LList L,L1,L2,L3;
	int kt = 0;
	Data x;
	Node *q;
	initList(&L);
	initList(&L1);
	initList(&L2);
	initList(&L3);
	do{
	    printf("\nChuong trinh lam viec voi DSLK kep SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Xoa nut o dau danh sach");
	    printf("\n5: Xoa nut o cuoi danh sach");
	    printf("\n6: Tach danh sach");
	    printf("\n7: Ghep danh sach");
	    printf("\n8: Xoa dau danh sach");
	    printf("\n10: Xoa sau danh sach");
	    printf("\n11: Xoa theo ten");
	    printf("\n12: Chen tang");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0){
	            int ma;
	            printf("Nhap ma sinh vien bi chen sau: ");
	            scanf("%d",&ma);
	            Node *q=L.pHead;
	            while(q!=NULL&&q->infor.masv!=ma){
	            	q=q->link;
				}
				if(q!=NULL){
                insert_After(&L,q,x);
                }
                }
            	break;
            case 4: 
				xoa_dau(&L);
                break;
            case 5:
            	if(x.masv>0){
            	Node *q=L.pHead;
            	while(q->link!=L.pTail){
            		q=q->link;
				}
            	xoa_cuoi(&L,q);
            }
            	break;
            case 6:
            	if(x.masv>0){
            		tach(L,&L1,&L2);
            		printf("diem < 5: \n");
            		processList(L1);
            		printf("diem > 5: \n");
            		processList(L2); 
				}
				break;
			case 7:
					ghep(&L3,L1,L2);
					printf("Danh sach sau ghep: \n");
					processList(L3);
				break;
			case 8:
				del_Head(&L);
				break;
			case 10:
				int ma;
				printf("Nhap ma sv: ");
				scanf("%d",&ma);
				q=tim(L,ma);
				if(q!=NULL) del_After(&L,q);
				else{
					printf("Khong tim thay ma %d\n",ma);
				}
				break;
			case 11:
			    char ten[30];
				printf("Nhap ten sv: ");
				scanf("%s",ten);
				del_K(&L,ten);
				break;
			case 12:
				nhap(&x);
				if(x.masv>0) chen_tang(&L,x);
				break;
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}

