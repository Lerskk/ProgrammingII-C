def makeSynonymsGroup(fileName): 
    path = "/home/lerskk/code/C/examThree/" + fileName
    file = open(path, 'r')
    dictionary = dict()
    index = 1

    for line in file.readlines()[1:]:
        if not line.split()[0].isdigit():
            dictionary[index] = {*line.split()}
            index += 1

    file.close()
    return dictionary

def makeRelations(fileName):
    path = "/home/lerskk/code/C/examThree/" + fileName
    file = open(path)
    dictionary = dict()
    
    for line in file.readlines()[1:]:
        key = line.split()[0]
        if key.isdigit():
            value = line.split()[1]
            dictionary[key] = value
            dictionary[value] = key

    file.close()
    return dictionary

def makeKeyRelation(fileName, directoryOfSets: dict):
    path = "/home/lerskk/code/C/examThree/" + fileName
    file = open(path)
    dictionary = dict()

    for setNumber, words in directoryOfSets.items():
        for word in words:
            dictionary[word] = setNumber 

    file.close()
    return dictionary

def getSynonyms(searchingFor, words, sets):
    for word, numberInSet in words.items():
        if (searchingFor == word):
            print(sets[numberInSet])
            return None
    print("ERROR: Word not found")
    return None

def getAntonyms(searchingFor, synonyms, antonymsRelations, words):
    rel = None
    for word, numberInSet in words.items():
        if (word == searchingFor):
            for relationKey, relationValue in antonymsRelations.items():
                if numberInSet == int(relationKey) - 1:
                   rel = int(relationValue) - 1
    for numberInSet, synonym in synonyms.items():
        if int(numberInSet) == rel:
            print(synonym)
            return None
    print("ERROR: Word not found or there are not synonyms")
    return None


def main():
    fileName = "output.txt"

    dictionaryOfSynonyms = makeSynonymsGroup(fileName)

    dictionaryOfAntonymsRelations = makeRelations(fileName)

    dictionaryOfWords = makeKeyRelation(fileName, dictionaryOfSynonyms)

    getSynonyms("hot", dictionaryOfWords, dictionaryOfSynonyms)
    getSynonyms("nothot", dictionaryOfWords, dictionaryOfSynonyms)

    getAntonyms("hot", dictionaryOfSynonyms, dictionaryOfAntonymsRelations, dictionaryOfWords)
    getAntonyms("nothot", dictionaryOfSynonyms, dictionaryOfAntonymsRelations, dictionaryOfWords)
    getAntonyms("chair", dictionaryOfSynonyms, dictionaryOfAntonymsRelations, dictionaryOfWords)
    getAntonyms("chilly", dictionaryOfSynonyms, dictionaryOfAntonymsRelations, dictionaryOfWords)


if __name__ == "__main__":
    main()
