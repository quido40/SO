#include <iostream>
using namespace std;

int main()
{
    int cantidad=0;
    int t_llegada, t_ejecucion;
	int conta=0;
    cout<<"ingrese la cantidad de procesos: "<<endl;
    cin>>cantidad;
    string titulo[7]={"Proceso","T_llegada","Duracion","T_inicio","T_final","Tiempo_R","Tiempo_E"};
    string proceso[cantidad];
    string auxproceso[cantidad];
    int temp_ll[cantidad];
	int mtabla[cantidad][6];
	int temporal[cantidad];
    cout<<"ingrese los PROCESOS :"<<endl;
	for(int i=0;i<cantidad;i++){
        cin>>proceso[i];
    }
    cout<<"ingrese los LOS TIEMPOS DE LLEGADA :"<<endl;
    int temp=0,su_duracion=0;
	for(int i=0;i<cantidad;i++){
		cin>>mtabla[i][0];
		temp_ll[i]=mtabla[i][0];
		if(mtabla[i][0]==0){
			conta++;
		}
    }
    cout<<"tiempos de llegada:="<<conta<<endl;
    temp=0;su_duracion=0;
	cout<<"Ingrese la DURACION :"<<endl;
    for(int i=0;i<cantidad;i++){
		cin>>mtabla[i][1];
		temp = mtabla[i][1];
		su_duracion = su_duracion + temp;
		temporal[i]=mtabla[i][1];
    }

    
    cout<<endl<<"duracion"<<su_duracion<<endl<<endl;
    
    int cont=0; 
	int menor=mtabla[0][0];
    int con=0; 
    int excluido,contador=0;
    int t_inicio=0,t_final=0;
    string grafico[cantidad][su_duracion];
	int c=0;
	//ordenando de menor a mayor la columna de DURACION
	int aux;
    for(int i=0;i<cantidad;i++){
		for(int j=i+1;j<cantidad;j++){
			if(temporal[i]>temporal[j]){
				aux=temporal[i];
				temporal[i]=temporal[j];
				temporal[j]=aux;
			}else{
				
			}
		}
		cout<<temporal[i]<<" : "<<endl;
    }
    //HALLANDO DE MENOR A MAYOR LOS TIEMPOS DE LLEGADA
    aux=0;;
    for(int i=0;i<cantidad;i++){
		for(int j=i+1;j<cantidad;j++){
			if(temp_ll[i]>temp_ll[j]){
				aux=temp_ll[i];
				temp_ll[i]=temp_ll[j];
				temp_ll[j]=aux;
			}else{
				
			}
		}
		cout<<"los: "<<temp_ll[i]<<" : "<<endl;
    }
    //graficando el SPN
    int aux1=1;
    for(int i=0;i<cantidad;i++){
		mtabla[i][2]=t_inicio;
		for(int a=0;a<cantidad;a++){
			for(int j=0;j<mtabla[a][1];j++){
				if(conta==cantidad){
					if(temporal[i]==mtabla[a][1]){
						grafico[a][j]=proceso[a];
						cout<<"hola aqui estoy: "<<endl;
						c++;
						t_final++;
						t_inicio++;
					}else{
					}

				}else {
					if(temp_ll[i]==mtabla[a][0]){
						if(temp_ll[i+1]==j){
							if((mtabla[a][1]-aux1)<mtabla[a+1][1]){
								grafico[a][j]=proceso[a];
								cout<<"if 1 :"<<endl;
								aux1++;	
							}else{
								grafico[a][j]=proceso[a];
								cout<<"else 1 :"<<endl;
							}
						}else{
							grafico[a][j]=proceso[a];
							cout<<"else 2 :"<<endl;
						}
					}else{
						
					}
				}
			}
		}	
		contador=c;
		mtabla[i][3]=t_final;
    }
//GRAFICANDO:D
    for(int i=0;i<cantidad;i++){
		cout<<proceso[i]<<"   ";
		for(int a=0;a<su_duracion;a++){
			cout<<grafico[i][a]<<"   ";
		}
		cout<<endl;
    }
   


    //realizamos el proceso para tiempo de retorno y tiempo de espera TR, TE , TRM y TEM
    float PTR=0, PTE=0;
    for(int i=0;i<cantidad;i++){
		for(int j=4;j<6;j++){
			if(j==4){
				mtabla[i][j]=mtabla[i][j-1]-mtabla[i][0];
				PTR=PTR+mtabla[i][j];
			}else{
				mtabla[i][j]=mtabla[i][j-3]-mtabla[i][0];
				PTE=PTE+mtabla[i][j];
			}
		}
    }
    
    
    cont=0;
    int eje_x[su_duracion+1];
    for(int i=0;i<su_duracion+1;i++){
		eje_x[i]=cont+i;
		cout<<eje_x[i]<<"   ";
    }
    cout<<endl;
    string cola[cantidad][su_duracion+1];
	for(int i=0;i<cantidad;i++){
		for(int j=0;j<su_duracion+1;j++){
				cola[i][j]="*";
				cout<<cola[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
    cout<<"imprimiendo tabla :"<<endl;
     for(int i=0;i<7;i++){
		cout<<titulo[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<cantidad;i++){
		cout<<auxproceso[i]<<"          ";
		for(int j=0;j<6;j++){
			cout<<mtabla[i][j]<<"          ";
		}
		cout<<endl;
    }
    cout<<endl;
    cout<<"TIEMPO DE RETORNO PROMEDIO(TRM): "<<PTR/cantidad<<endl;
    cout<<"TIEMPO DE ESPACIO PROMEDIO(TEM):  "<<PTE/cantidad<<endl;
    return 0;
}
