def calDir(start, end):
    return [end[0] - start[0], end[1] - start[1]]

def gcd(a, b):
    a, b = abs(a), abs(b)
    while b > 0:
        a, b = b, a % b
    return a

def GetDirectionName(mirror_vector):
    if mirror_vector[0] == 0 and mirror_vector[1] == 0:
        return 0, 0
    elif mirror_vector[0] == 0:
        return 0, 1 if mirror_vector[1] > 0 else -1
    elif mirror_vector[1] == 0:
        return 1 if mirror_vector[0] > 0 else -1, 0
    else:
        vector_gcd = gcd(*mirror_vector)
        return mirror_vector[0] / vector_gcd, mirror_vector[1] / vector_gcd

def calDis(direction):
    return (pow(direction[0],2) + pow(direction[1],2)) ** 0.5


def GetPointAtBox(dimension, index, point):
    return (dimension * index) + ((dimension - point) if index % 2 != 0 else point)

def GetPositionAtBox(dimensions, box, position):
    return [GetPointAtBox(dimensions[0], box[1], position[0]), GetPointAtBox(dimensions[1], box[0], position[1])]


def answer(dimensions, your_position, guard_position, distance):
    YouToGuardDistance = calDis(calDir(your_position, guard_position))
    if YouToGuardDistance > distance:
        return 0
    elif YouToGuardDistance == distance:
        return 1

    NumberOfRow = distance / dimensions[1] + 3
    NumberOfCol = distance / dimensions[0] + 3
    shoot_directions = dict()

    rowIndex = NumberOfRow
    colIndex = NumberOfCol

    counter = 0
    while rowIndex >= 0 or colIndex >= 0:
        for col in xrange(-colIndex, colIndex + 1):
            for row in [rowIndex, -rowIndex]:
                newGuardPos = GetPositionAtBox(dimensions, [row,col], guard_position)
                DirectionName = GetDirectionName(calDir(your_position, newGuardPos))
                if calDis(calDir(your_position, newGuardPos)) <= distance: 
                    if DirectionName not in shoot_directions :
                        shoot_directions[DirectionName] = True
                newYourPos = GetPositionAtBox(dimensions, [row, col], your_position)
                DirectionName = GetDirectionName(calDir(your_position, newYourPos))
                if DirectionName in shoot_directions:
                    del shoot_directions[DirectionName]
        for row in xrange(-rowIndex + 1, rowIndex):
            for col in [colIndex, -colIndex]:
                newGuardPos = GetPositionAtBox(dimensions, [row,col], guard_position)
                DirectionName = GetDirectionName(calDir(your_position, newGuardPos))
                if calDis(calDir(your_position, newGuardPos)) <= distance: 
                    if DirectionName not in shoot_directions :
                        shoot_directions[DirectionName] = True
                newYourPos = GetPositionAtBox(dimensions, [row, col], your_position)
                DirectionName = GetDirectionName(calDir(your_position, newYourPos))
                if DirectionName in shoot_directions:
                    del shoot_directions[DirectionName]
        rowIndex = rowIndex - 1
        colIndex = colIndex - 1
    
    for key, value in shoot_directions.iteritems():
        if value:
            counter = counter + 1
    return counter


print(answer([3,2],[1,1],[2,1],4))
print(answer([2,5],[1,2],[1,4],11))
print(answer([10,10],[4,4],[3,3],5000))
print(answer([23,10],[6,4],[3,2],23))
print(answer([300,275],[150,150],[185,100],500))