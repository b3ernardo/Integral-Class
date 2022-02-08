#include <iostream>
#include <cmath>

using namespace std;

class Funcao {
  public:
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos) {
      double soma = 0, altura, baseInferior, baseSuperior;
      
      altura = (limiteSuperior - limiteInferior) / intervalos;
      baseInferior = limiteInferior;
      baseSuperior = baseInferior + altura;

      for (int i = 0; i < intervalos; i++) {
        soma += ((func(baseInferior) + func(baseSuperior)) * altura / 2);
        baseInferior = baseSuperior;
        baseSuperior = baseInferior + altura;
      }
      
      return soma;
    }

    virtual double func(double input) = 0;

    virtual ~Funcao() {}
};

class Quadratica : public Funcao {
  private:
    double a, b, c;
  public:
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);
    
    Quadratica(double _a, double _b, double _c) {
      a = _a;
      b = _b;
      c = _c;
    }

    double func(double x) {return ((a * pow(x, 2)) + (b * x) + c);}
};

class Senoidal : public Funcao {
  public:
    Senoidal() {};

    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);
    
    double func(double x) {return (sin(x) / x);}
};

class Linear : public Funcao {
  private:
    double a, b;
  public:
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);
    
    Linear(double _a, double _b) {
      a = _a;
      b = _b;
    }
    
    double func(double x) {return ((a * x) + b);}
};

int main() {
  double resultado;
  Funcao *f[3];
  f[0] = new Quadratica(1, 2, 4);
  f[1] = new Senoidal();
  f[2] = new Linear(1, 4);

  cout << "*** Calculo de integrais usando a regra do trapezio: ***" << endl << endl;
  cout << "*** Funcoes ***" << endl;
  cout << "(1) x^2 + 2x + 4" << endl;
  cout << "(2) sen(x) / x" << endl;
  cout << "(3) x + 4" << endl;
  cout << endl;

  for (int i = 0; i < 3; i++) {
    resultado = f[i]->getIntegral(1, 4, 1000);
    cout << "Integral da Funcao (" << i + 1 << "): " << resultado;
    cout << endl;
  }

  for (int i = 0; i < 3; i++)
    delete f[i];

  return 0;
}