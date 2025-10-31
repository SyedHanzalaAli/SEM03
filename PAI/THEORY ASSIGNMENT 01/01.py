transactionLog = [
    {'orderId': 1001, 'customerId': 'cust_Ahmed', 'productId': 'prod_10'},
    {'orderId': 1001, 'customerId': 'cust_Ahmed', 'productId': 'prod_12'},
    {'orderId': 1002, 'customerId': 'cust_Bisma', 'productId': 'prod_10'},
    {'orderId': 1002, 'customerId': 'cust_Bisma', 'productId': 'prod_15'},
    {'orderId': 1003, 'customerId': 'cust_Ahmed', 'productId': 'prod_15'},
    {'orderId': 1004, 'customerId': 'cust_Faisal', 'productId': 'prod_10'},
    {'orderId': 1004, 'customerId': 'cust_Faisal', 'productId': 'prod_12'},
]

productCatalog = {
    'prod_10': 'Wireless Mouse',
    'prod_12': 'Keyboard',
    'prod_15': 'USB-C Hub',
}

def processTransaction(transactionList):
    customerData = {}
    for record in transactionList:
        customer = record['customerId']
        product = record['productId'] 
        if customer not in customerData:
            customerData[customer] = set()
        customerData[customer].add(product)
    return customerData


def findFrequentPairs(customerData):
    pairCount = {}

    for products in customerData.values():
        productList = sorted(list(products))

        for i in range(len(productList)):
            for j in range(i+1 ,len(productList)):
                pair = (productList[i] , productList[j])
                if pair not in pairCount:
                    pairCount[pair] = 0
                pairCount[pair] += 1
    return pairCount

def getRecommendation(targetProductId , frequentPairs):
    recommendations = {}
    for (p1,p2) , count in frequentPairs.items():
        if targetProductId in (p1,p2):
            other = p2 if p1 == targetProductId else p1
            recommendations[other] = count
    return sorted(recommendations.items() , key= lambda x : x[1] , reverse=True)

def generateReport(targetProductId , recommendations , catalog):
    print(f"\nRecommendations for {catalog[targetProductId]} :\n")

    pID = [prod for prod , count in recommendations]
    counts = [count for prod , count in recommendations]

    combine = zip(pID , counts)

    for i , (prod , count) in enumerate(combine , start=1):
        productName = catalog[prod]
        print(f"{i}. {productName} , bought together {count} times")


def main():
    customerData = processTransaction(transactionLog)
    frequentPairs = findFrequentPairs(customerData)
    recs = getRecommendation('prod_12' , frequentPairs)
    generateReport('prod_12' , recs , productCatalog)

main()
