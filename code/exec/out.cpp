#include<iostream>
#include<vector>
#include"complex.h"
#include"matrix.h"
#include"type.h"
#include"state.h"
#include"list_func.h"
#include<math.h>

using namespace std;

Matrix X = Matrix(2);
Matrix Y = Matrix(2);
Matrix Z = Matrix(2);
Matrix H = Matrix(2);
int initializeGate(Matrix x,Complex a,Complex b,Complex c,Complex d){
	x.set_entry(0,0,a);
	x.set_entry(0,1,b);
	x.set_entry(1,0,c);
	x.set_entry(1,1,d);
	if(x.is_unitary()) return 1;
	return 0;
}

int num_iterations = 1000;
int quantum_registers = 3;
int quantum_registers_original = 3;
int classical_registers = 3;

int quantum_register_dict[3];
Matrix op = Matrix(1<<quantum_registers)
;int quantum_register_map(int i){
if( (i>= 3) || (i<0) || (quantum_register_dict[i] == -1))
{throw std::runtime_error("Semantic Error: Invalid quantum register access");}
return quantum_register_dict[i];
}
struct Quantum q[3] = {Quantum(Complex(1.000000,0.000000),Complex(0.000000,0.000000)),Quantum(Complex(1.000000,0.000000),Complex(0.000000,0.000000)),Quantum(Complex(0.000000,0.000000),Complex(0.000000,1.000000))};
StateVec q_output_original = StateVec(3,q);
StateVec q_output = StateVec(3,q);
int c_output[3] = {0,0,0};
int c_output_original[3] = {0,0,0};
vector<unsigned int> c_master(3, 0);
Matrix BellGen(int i, int j){
op = H.kronecker_control_fill(0, quantum_register_map(i), quantum_registers) * op;
op = X.kronecker_control_fill((1<<quantum_register_map(i)), quantum_register_map(j), quantum_registers) * op;
return op;
}

int main(){
for(int i=0; i<quantum_registers; i++) {quantum_register_dict[i] = i;}
initializeGate(X,Complex(0,0),Complex(1,0),Complex(1,0),Complex(0,0));
initializeGate(Y,Complex(0,0),Complex(0,-1),Complex(0,1),Complex(0,0));
initializeGate(Z,Complex(1,0),Complex(0,0),Complex(0,0),Complex(-1,0));
initializeGate(H,Complex(1/sqrt(2),0),Complex(1/sqrt(2),0),Complex(1/sqrt(2),0),Complex(-1/sqrt(2),0));
FILE *result = fopen("result.csv","w");
for(int iters=0;iters < num_iterations;iters++){
q_output = StateVec(3, q);
for(int i=0;i<3;i++){
		c_output[i] = c_output_original[i];
}
for(int i=0;i<3;i++){
		quantum_register_dict[i] = i;
}
quantum_registers = quantum_registers_original;
op = Matrix(1 << quantum_registers);
op = BellGen(1, 2);
q_output = q_output.transform(op);
op = Matrix(1<<quantum_registers);
op = X.kronecker_control_fill((1<<quantum_register_map(0)), quantum_register_map(1), quantum_registers) * op;
op = H.kronecker_control_fill(0, quantum_register_map(0), quantum_registers) * op;
q_output = q_output.transform(op);
c_output[0] = q_output.measure_prob(quantum_register_map(0));
quantum_registers--;
op = Matrix(1<<quantum_registers);
quantum_register_dict[0] = -1;
for(int i=0+1; i<3; i++){quantum_register_dict[i]--;}
q_output = q_output.transform(op);
c_output[1] = q_output.measure_prob(quantum_register_map(1));
quantum_registers--;
op = Matrix(1<<quantum_registers);
quantum_register_dict[1] = -1;
for(int i=1+1; i<3; i++){quantum_register_dict[i]--;}
if(c_output[1]) {
op = X.kronecker_control_fill(0, quantum_register_map(2), quantum_registers) * op;
}
if(c_output[0]) {
op = Z.kronecker_control_fill(0, quantum_register_map(2), quantum_registers) * op;
}
for(int i=0;i<classical_registers;i++){
c_master[i] += c_output[i];
}
fprintf(result,"Iteration #%d:\n",iters+1);
fprintf(result,"Classical Outputs: ");for(int i=0;i<3-1;i++){
		fprintf(result,"%d, ",c_output[i]);
}
fprintf(result,"%d\n",c_output[3-1]);
fprintf(result,"Quantum Outputs: ");for(int i=0;i< (1 << quantum_registers) ;i++){
		fprintf(result,"(%f, %f), ",q_output.get_value(i).get_real(),q_output.get_value(i).get_imag());
}
fprintf(result,"\n\n");}
fclose(result);
int a = 1;
int i = 0;
for(i = 1;i < 2;i += 1){
int a = 3;
int j = 0;
for(j = 4;j < 6;j += 1){
int a = 7;
int j = 8;
a = a + 1;
}
int y = 9;
}
}
