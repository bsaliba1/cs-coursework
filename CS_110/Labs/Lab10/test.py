import tile
import gameboard

print("##Testing Tile Model##")

tile_test= tile.Tile(1,1);
value = ['*','','1']

for i in value:
    tile_test.value = i
    if i == '*':
        print "##testing to see if '*' returns True for isMine and False for is Empty##"
    if i == '':
        print "##testing to see if '' returtns false for isMine and True for is Empty##"
    if i == '1':
        print "##testing to see if '1' returns false for both is mine and is empty##"
    print(tile_test.isMine())
    print(tile_test.isEmpty())
    
    
# print False
print "flip test should equal false"
print(tile_test.isFlipped)
tile_test.flip()

# print True
print "after flip should equal true"
print(tile_test.isFlipped)

tile_test.flip()#should return true
tile_test.flag()#should return true

print("###Testing Gameboard Model##")

alltests = [(5,5,3), (4,4,4), (9,9,9), (7,7,15)]

for testn in alltests:
    testboard1 = gameboard.GameBoard(testn[0],testn[1],testn[2])
    testboard1.createBoard()
    testboard1.placeMines()
    testboard1.fillBoard()
    

