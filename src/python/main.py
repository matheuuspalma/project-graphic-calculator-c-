#Gustavo Rocha de Barros
#DRE: 119050063
#Avaliação Final


#Imports
import numpy as np
import matplotlib.pyplot as plt
import cmath

#Funcoes
def polinomio (x, coeficientes):
    grau = len(coeficientes) - 1
    resultado = sum(coeficientes[i] * (x ** (grau - i)) for i in range(grau +1))
    return resultado


def plotar_polinomio(coeficientes):

    x_valores = np.linspace (-10, 10, 1000)

    y_valores = [polinomio(x, coeficientes) for x in x_valores]

    plt.plot(x_valores, y_valores, label='Polinomio')

    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Gráfico do Polinomio')


    plt.legend()
    plt.grid(True)
    plt.show()

coeficientes = []
plotar_polinomio(coeficientes) 




def polar_2_retang(r, theta):
    real_part = r * cmath.cos(theta)
    imag_part = r * cmath.sin(theta)
    return complex(real_part, imag_part)


def retang_2_polar (real_part, imag_part):
    z = complex(real_part, imag_part)
    r = abs(z)
    theta = cmath.phase(z)
    return r, theta



def pot_recur(base, expoente):
    if expoente == 0:
        return 1
    else:
        return base * pot_recur (base, expoente -1)


def raiz_quad_recur(n, aprox = 1e-10, chute_inicial = None):
    def bissecao(chute):
        return (chute + n / chute) / 2.0
    if chute_inicial is None:
        chute_inicial = n / 2.0
    if abs (chute_inicial - bissecao(chute_inicial)) < aprox:
        return chute_inicial
    else:
        return raiz_quad_recur(n, aprox, bissecao(chute_inicial))


def deci_2_bin(n):
    return bin(n)

def deci_2_octal(n):
    return oct(n)

def deci_2_hex(n):
    return hex(n)
