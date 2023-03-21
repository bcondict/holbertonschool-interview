#!/usr/bin/python3
''' Challenge 0 - N queens, N size table '''


import sys


def main():
    ''' main function '''

    ''' check if the number of arguments is correct '''
    try:
        queen_num = sys.argv[1]
    except IndexError:
        print("Usage: nqueens N")
        sys.exit(1)

    '''
        check if the number is valid
        must be a number
    '''
    try:
        queen_num = int(queen_num)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    ''' minimum 4 queens in a 4x4 table '''
    if queen_num < 4:
        print("N must be at least 4")
        sys.exit(1)

    ''' board is a list of lists with the position of the queens'''
    board = []

    ''' forbidden is a list of lists with the position of the forbidden '''
    forbidden = []

    '''
        last_queen is a list with the position of the last queen
        first position to last index of the board just for the first time
    '''
    last_queen = [queen_num, queen_num]

    ''' current_queen is the number of the current queen '''
    current_queen = 0

    '''
        dictionary with the position of the forbidden for each queen
        for each queen, the key is the number of the queen
    '''
    new_dict = {0: []}

    '''i and j are the position of the current queen'''
    i, j = 0, 0

    '''Row of the board'''
    while i < queen_num:

        '''reset the column'''
        j = 0

        '''Colum of the board'''
        while j < queen_num:

            '''
                check if is not the last queen, first iteration always true
                check if the position is valid, non-atacking position
                check if the position is not in the forbidden list
                check if the position is not in the in forbidden list of the
                current queen in the dictionary

                if all are valid add a new queen to the board in the position
            '''
            if (last_queen != [i, j] and valid([i, j], board)
                and [i, j] not in forbidden and [i, j]
                    not in new_dict[current_queen]):

                current_queen += 1
                last_queen = [i, j]

                '''
                    check if the queen is in the dictionary
                    and removes it from the list
                '''
                try:
                    if (last_queen in new_dict[current_queen]):
                        last_queen = board[len(board) - 2]
                        current_queen -= 1
                        break
                except KeyError:
                    pass

                ''' add new queen to the board'''
                board.append(last_queen)

                ''' add the position to the forbidden list'''
                forbidden = [last_queen]

                '''
                    add the position to the forbidden list of the current
                    queen in the dictionary

                    if the queen is not in the dictionary, add it on except
                '''
                try:
                    new_dict[current_queen] = new_dict[current_queen]
                    new_dict[current_queen].append([i, j])
                except KeyError:
                    new_dict[current_queen] = [[i, j]]

            '''
                if the board is full, print the board and delete
                the last queen and add the position to the forbidden list
                go back to the last queen and check another posibility
            '''
            if (len(board) == queen_num):
                print(board)
                last_queen = board[len(board) - 2]
                current_queen -= 1
                i = last_queen[0]
                j = last_queen[1]
                board.pop()

            '''
                if last position reached and the board is not full
            '''
            if (i == queen_num - 1 and j == queen_num - 1
                    and len(board) < queen_num):

                '''
                    add new forbidden position to the dictionary
                    for current queen
                '''
                forbidden = new_dict[current_queen]

                ''' last queen before old last queen'''
                last_queen = board[len(board) - 2]

                ''' position of the old last queen'''
                i = last_queen[0]
                j = last_queen[1]

                ''' remove the old last queen'''
                board.pop()

                '''
                    remove the forbidden position for next queen
                    of old last queen
                '''
                if (len(new_dict) > len(board) + 2):
                    new_dict[current_queen + 1] = []

                ''' number of queen decreses by 1 deletion '''
                current_queen -= 1

            j += 1

        i += 1


''' check if the position is valid '''


def valid(current, board):

    ''' travel the board '''
    for queen in board:

        ''' check if the position is valid on horizontal or vertical '''
        if (current[0] == queen[0] or current[1] == queen[1]):
            return False

        ''' check if the position is valid on diagonal '''
        if (abs(current[0] - queen[0]) == abs(current[1] - queen[1])):
            return False
    return True


if __name__ == "__main__":
    main()
