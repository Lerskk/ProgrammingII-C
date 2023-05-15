def bubbleSort(list):
    swapped = True

    while swapped:
        swapped = False
        for iElement in range(len(list) - 1):
            if list[iElement] > list[iElement + 1]:
                temp = list[iElement]
                list[iElement] = list[iElement + 1]
                list[iElement + 1] = temp
                swapped = True
    return list


def insertionSort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

    return arr


def merge(listOne, listTwo):
    sortedList = []
    notFinish = True
    i = 0
    j = 0

    while notFinish:
        if i == len(listOne):
            return sortedList + listTwo
        if j == len(listTwo):
            return sortedList + listOne
        if listOne[i] < listTwo[j]:
            sortedList.append(listOne[i])
            i += 1
        else:
            sortedList.append(listTwo[j])
            j += 1

    return sortedList


def mergeSort(list):
    if len(list) < 2:
        return list
    middle = len(list) // 2
    listOne = list[:middle]
    listTwo = list[middle:]

    sortedOne = mergeSort(listOne)
    sortedTwo = mergeSort(listTwo)

    return merge(sortedOne, sortedTwo)


list = [1, 2, 3, 4]
print(mergeSort(list))
