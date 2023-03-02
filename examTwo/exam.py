def input(fileName):
    file = open(fileName)
    people = []
    for person in file:
        personData = person.split(',')
        personData[-1] = personData[-1][:-1]
        people.append(personData)
    return people

def filterOldPeople(people):
    oldPeople = []
    for person in people:
        if 16 < person[3]:
            oldPeople.append(person)
    return oldPeople

def filterYoungPeople(people):
    youngPeople = []
    for person in people:
        if person[3] <= 16 :
            youngPeople.append(person)
    return youngPeople

def main():
    print(input("saveFile.txt"))
    
if __name__ == '__main__':
    main()
