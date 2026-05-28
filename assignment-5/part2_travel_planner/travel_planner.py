import json

with open("knowledge_base.json", "r") as file:
    data = json.load(file)

print("AI Based Travel Planner")
print()

budget = int(input("Enter your budget: "))
travel_type = input("Enter preferred travel type: ")

print()
print("Recommended Destinations:")
print()

found = False

for city, details in data.items():

    if budget >= details["budget"] and travel_type.lower() == details["type"].lower():

        found = True

        print("City:", city)
        print("Budget:", details["budget"])
        print("Tourist Places:", ", ".join(details["places"]))
        print("Food Recommendations:", ", ".join(details["food"]))
        print()

if not found:
    print("No matching destinations found.")
