#include <iostream>
#include <stdexcept>
#include "matrix.h"
#include "math.h"

/* Helpers */
unsigned int pow_two(unsigned int n)
{
    if(n == 0) return -1;
    if(n & (n - 1)) return -1;
    return floor(log2(n));
}

int string_and(std::string a, std::string b)
{
    /* Prefix */
    int max = a.length();
    if(a.length() > b.length()) 
    {
        std::string temp(a.length() - b.length(), '0');
        b = temp + b;
    }
    else if(b.length() > a.length())
    {
        max = b.length();
        std::string temp(b.length() - a.length(), '0');
        a = temp + a;
    }

    /* Compute dot */
    int result = 0;
    for(int i = 0; i < max; i++) if((a[i] == '1') && (b[i] == '1')) result += 1;
    return result;
}

/* Constructors */
Matrix::Matrix(unsigned int m)
{
    n = m;
    arr = (Complex**)malloc(n*sizeof(Complex*));
    for(int i = 0; i < n; i++)
    {
        arr[i] = (Complex*)malloc(n*sizeof(Complex));
        for(int j = 0; j < n; j++)
        {
            if(i == j) arr[i][j] = Complex(1, 0);
            else arr[i][j] = Complex();
        }
    }
}

/* Set Functions */
void Matrix::set_entry(unsigned int i, unsigned int j, Complex c)
{
    if((i >= n) || (j >= n)) throw std::invalid_argument("Out of bounds!!!");
    arr[i][j] = c;
}

/* Get Function */
Complex Matrix::get_entry(unsigned int i, unsigned int j) const
{
    if((i >= n) || (j >= n)) throw std::invalid_argument("Out of bounds!!!");
    return arr[i][j];
}

Complex** Matrix::get_arr()
{
    return arr;
}

unsigned int Matrix::get_dim() const
{
    return this->n;
}

/* Operators */
Matrix Matrix::operator+(Matrix const& op)
{
    if(n != op.get_dim()) throw std::invalid_argument("Incompatible Matrices!");
    Matrix ans = Matrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans.arr[i][j] = arr[i][j] + op.arr[i][j];
        }
    }
    return ans;
}

Matrix Matrix::operator-(Matrix const& op)
{
    if(n != op.get_dim()) throw std::invalid_argument("Incompatible Matrices!");
    Matrix ans = Matrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans.arr[i][j] = arr[i][j] - op.arr[i][j];
        }
    }
    return ans;
}

Matrix Matrix::operator*(Matrix const& op)
{
    if(n != op.get_dim()) throw std::invalid_argument("Incompatible Matrices!");
    Matrix ans = Matrix(n);
    Complex temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp = Complex();
            for(int k = 0; k < n; k++)
            {
                temp = temp + arr[i][k] * op.arr[k][j];
            }
            ans.arr[i][j] = temp;
        }
    }
    return ans;
}

Matrix Matrix::operator*(Complex const& op)
{
    Matrix ans = Matrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) ans.arr[i][j] = arr[i][j] * op;
    }
    return ans;
}

Matrix Matrix::operator/(const int a)
{
    Matrix ans = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            ans.arr[j][i] = this->arr[i][j]/float(a);
        }
    }
    return ans;
}

Matrix Matrix::operator!()
{
    Matrix ans = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            ans.arr[j][i] = !arr[i][j];
        }
    }
    return ans;
}

/* Misc */
bool Matrix::is_unitary() const
{
    Matrix cpy = *this;
    Matrix ans = (!cpy)*(cpy);
    ans.show();
    Matrix eye = Matrix(this->n);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            if(eye.arr[i][j] != ans.arr[i][j]) return false;
        }
    }
    return true;
}

/* Resize */
void Matrix::resize(unsigned int m)
{
    //free(this->arr);
    n = m;
    arr = (Complex**)malloc(m*sizeof(Complex*));
    for(int i = 0; i < m; i++)
    {
        arr[i] = (Complex*)malloc(m*sizeof(Complex));
        for(int j = 0; j < m; j++)
        {
            if(i == j) arr[i][j] = Complex(1, 0);
            else arr[i][j] = Complex();
        }
    }
}

/* Show */
void Matrix::show()
{
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << arr[i][j].to_str() << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

/* Kronecker product */
Matrix Matrix::kronecker_product(Matrix sample) /* Computes [THIS # SAMPLE] */
{
    //if((pow_two(n) < 0) || (pow_two(sample.n) < 0)) throw std::invalid_argument("Incompatible Matrices for Kronecker-Product!");

    Matrix ans = Matrix(n * sample.n);
    Complex temp;

    /* Compute */
    for(int out_i = 0; out_i < n; out_i++)
    {
        for(int out_j = 0; out_j < n; out_j++)
        {
            temp = arr[out_i][out_j];
            for(int inn_i = 0; inn_i < sample.n; inn_i++)
            {
                for(int inn_j = 0; inn_j < sample.n; inn_j++)
                {
                    ans.arr[out_i*sample.n + inn_i][out_j*sample.n + inn_j] = temp * sample.arr[inn_i][inn_j];
                }
            }
        }
    }

    /* Return */
    return ans;
}

/* Kronecker Fill */
Matrix Matrix::kronecker_fill(unsigned int place, unsigned int regs) /* Only for 2*2 matrices */
{
    if(n != 2) throw std::invalid_argument("Incompatible Matrices for Kronecker-Fill!");
    if(place >= regs) throw std::invalid_argument("Place out of bounds!");

    Matrix ans = Matrix(1<<regs);

    if(place == 0) ans = Matrix(1 << (regs-1)).kronecker_product(*this); 
    else if(place == regs-1) ans = this->kronecker_product(Matrix(1 << (regs-1)));
    else ans = Matrix(1 << (regs-place-1)).kronecker_product(this->kronecker_fill(place, place+1));
    
    /* Return */
    std::cout << ans << std::endl;
    return ans;
}

/* Kronecker Control fill */
/* Note: If control consists of (2, 4, 5) : then control = 000000110100 */
/* Note: If target is 7: then target = 000010000000*/
Matrix Matrix::kronecker_control_fill(unsigned int control, unsigned int target, unsigned int regs)
{
    unsigned int target_bits = 1<<target;

    if(control==0) return kronecker_fill(target, regs);
    if(n != 2) throw std::invalid_argument("Incompatible Matrices for Kronecker-Control-Fill!");
    if((control & target_bits) != 0) throw std::invalid_argument("Target inside Control Registers!");
    if(pow_two(target_bits) == -1) throw std::invalid_argument("Only one target allowed!");

    Matrix ans = Matrix(1<<regs);
    unsigned int a, b;

    for(int i = 0; i < (1<<regs); i++)
    {
        if((control & i) != control) continue;
        (i & target_bits) ? (a = 1) : (a = 0);
        for(int j = 0; j < (1<<regs); j++)
        {
            if((control & j) != control) continue;
            (j & target_bits) ? (b = 1) : (b = 0);
            ans.arr[i][j] = arr[a][b];
        }
    }

    return ans;
}

std::ostream &operator<<(std::ostream &os, Matrix const &m) { 
    os << "--------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < m.n; i++)
    {
        for(int j = 0; j < m.n; j++)
        {
            os << m.arr[i][j].to_str() << "\t";
        }
        os << "\n";
    }
    os << "--------------------------------------------------------------------------\n" << std::endl;
    return os;
}