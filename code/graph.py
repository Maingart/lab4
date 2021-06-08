import matplotlib.pyplot as plt


def drawXY(x, y):
    plt.plot(x, y)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.savefig('../img/dist/predator1.pdf')
    plt.close()


def drawT(x, y):
    t = range(0, len(x))
    plt.plot(t, x)
    plt.plot(t, y)
    plt.xlabel('Время')
    plt.ylabel('Особи')
    plt.savefig('../img/dist/predator2.pdf')
    plt.close()


x, y = [], []

f = open('results.txt', 'r').read().split('\n')

for _ in f:
    if _:
        _x, _y = map(float, _.split())
        x.append(_x)
        y.append(_y)

drawXY(x, y)
drawT(x, y)
