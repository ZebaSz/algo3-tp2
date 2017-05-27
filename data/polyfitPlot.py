import pylab, random

def getData(fileName):
    dataFile = open(fileName, 'r')
    inputSize = []
    timeTaken = []
    discardHeader = dataFile.readline()
    for line in dataFile:
        d, m = line.split(',')
        inputSize.append(float(d))
        timeTaken.append(float(m))
    dataFile.close()
    return (inputSize, timeTaken)

def plotData(fileName):
    xVals, yVals = getData(fileName)
    xVals = pylab.array(xVals)
    yVals = pylab.array(yVals)
    pylab.plot(xVals, yVals, 'bo', label = 'tiempos dp')
    pylab.title('ej3')
    pylab.xlabel('Tamaño de entrada')
    pylab.ylabel('Tiempo demorado')

##plotData('EJEMPLO DP TP1')
##pylab.show()

def rSquare(measured, estimated):
    """measured: one dimensional array of measured values
       estimate: one dimensional array of predicted values"""
    SEE = ((estimated - measured)**2).sum()
    mMean = measured.sum()/float(len(measured))
    MV = ((mMean - measured)**2).sum()
    return 1 - SEE/MV

def fitData(fileName):
    xVals, yVals = getData(fileName)
    xVals = pylab.array(xVals)
    yVals = pylab.array(yVals)
    pylab.plot(xVals, yVals, 'bo', label = 'Measured points')
    pylab.title('Measured time taken by algorithm')
    pylab.xlabel('vector size')
    pylab.ylabel('time (miliseconds)')
    a,b,c,d = pylab.polyfit(xVals, yVals, 3)  # fit y = ax³ + bx² + cx + d
    # use line equation to graph predicted values
    estYVals = a*(xVals**3) + b*(xVals**2) + c * xVals + d
    # plot estimated array and show the cuadratic error of the prediction
    pylab.plot(xVals, estYVals, label = 'Cubic fit, Cuadratic error = ' \
        + str(round(rSquare(yVals, estYVals), 4)) )
    pylab.legend(loc = 'best')

fitData('EJEMPLO DP TP1')
pylab.show()
