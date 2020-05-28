import math
X = int(input())
crossLayerOrder = math.ceil((-1 + math.sqrt(1+8*X))/2)
orderInLayer = int(X - (crossLayerOrder-1)*(crossLayerOrder)/2)
if crossLayerOrder % 2 == 0:
    print("{}/{}".format(orderInLayer, crossLayerOrder-orderInLayer+1))
else:
    print("{}/{}".format(crossLayerOrder-orderInLayer+1, orderInLayer))
