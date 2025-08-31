countryPopulation = {
    "China": 1444216107,
    "India": 1393409038,
    "USA": 332915073,
    "Indonesia": 276361783,
    "Pakistan": 225199937,
    "Brazil": 213993437
}

top = []

for i in range(3):
    maxPopulation = -1
    maxCountry = ""

    for country, population in countryPopulation.items():
        if country not in top and population > maxPopulation:
            maxPopulation = population
            maxCountry = country

    top.append(maxCountry)

print("top 3 most populated countries: ")
print(top)