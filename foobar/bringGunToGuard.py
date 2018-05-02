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

    for row in xrange(-rowIndex, rowIndex):
        for col in xrange(-colIndex, colIndex):
            newYourPos = GetPositionAtBox(dimensions, [row, col], your_position)
            YouToYou = calDir(your_position, newYourPos)
            if calDis(YouToYou) <= distance:
                YouToYouName = GetDirectionName(YouToYou)
                YouToYouDis  = calDis(YouToYou)
                if YouToYouName in shoot_directions:
                    if shoot_directions[YouToYouName][1] > YouToYouDis:
                        shoot_directions[YouToYouName] = [False, YouToYouDis]
                else:
                    shoot_directions[YouToYouName] = [False, YouToYouDis]
            
            newGuardPos = GetPositionAtBox(dimensions, [row,col], guard_position)
            YouToGuard = calDir(your_position, newGuardPos)
            if calDis(YouToGuard) <= distance:
                YouToGuardName = GetDirectionName(YouToGuard)
                YouToGuardDis  = calDis(YouToGuard)
                if YouToGuardName in shoot_directions:
                    if shoot_directions[YouToGuardName][1] > YouToGuardDis:
                        shoot_directions[YouToGuardName] = [True, YouToGuardDis]
                else:
                    shoot_directions[YouToGuardName] = [True, YouToGuardDis]

    counter = 0
    for key, value in shoot_directions.iteritems():
        if value[0]:
            counter = counter + 1
    return counter