import pygame

####PROBLEMS TO FIX#####
#1. HOVERING OVER BUTTONS DOES NOT TURN THEM LIGHT GREY
#2. CAN STILL CLICK BUTTONS WHEN IN SETTINGS, HELP, AND HIGHSCORE SCREEN

d_grey= (160,160,160)
dd_grey= (80,80,80)
l_grey=(220,220,220)
black= (0,0,0)
blue = (33,70,255)

display_width = 800
display_height= 600

box_width = 600
box_height = 100
pygame.init()

gameDisplay = pygame.display.set_mode((display_width,display_height))

font = pygame.font.SysFont(None,100)
medfont = pygame.font.SysFont(None,40)
smallfont= pygame.font.SysFont(None, 25)

menu = 'MAIN'

def text_objects(text,color,size):
	if size == 'small':
		textSurface = smallfont.render(text,True,color)
		return textSurface,textSurface.get_rect()
	if size == 'medium':
		textSurface = medfont.render(text,True,color)
		return textSurface,textSurface.get_rect()
	if size == 'large':
		textSurface = font.render(text,True,color)
		return textSurface,textSurface.get_rect()

class Button:
    def __init__(self, text,position,size,color,button_width=box_width,button_height=box_height):
    	self.position = position
    	self.x= position[0]
    	self.y=position[1]
    	self.width = button_width
    	self.height = button_height
    	self.rect = pygame.Rect(self.x,self.y,self.width,self.height)
    	self.text=text
    	self.size = size
    	self.color = color
    	self.button_width = button_width
    	self.button_height = button_height

    def button(self,height=box_height,inactive_c=dd_grey):
    	pygame.draw.rect(gameDisplay,inactive_c,(self.x,self.y,self.width,self.height))
    	Button.button_text(self.text,self.x+self.width/2,self.y+self.height/2,self.color,self.size)
    #takes in mouse position
    def update(self,cur):
    	if self.x+self.width>cur[0]>self.x and self.y+self.height>cur[1]>self.y:
    		pygame.draw.rect(gameDisplay,d_grey,(self.x,self.y,self.width,self.height))
    	else:
    		self.button()

    def button_text(text,x,y,color,size):
    	textSurf, textRect = text_objects(text,color,size)
    	textRect.center = (x,y)
    	gameDisplay.blit(textSurf,textRect)


buttons = {}

buttons['MAIN'] = []
buttons['MAIN'].append(Button('HELP',(100,220),'large',black))
buttons['MAIN'].append(Button('SETTINGS',(100,100),'large',black))
buttons['MAIN'].append(Button('HIGHSCORE',(100,340),'large',black))


buttons['SETTINGS'] = []
buttons['SETTINGS'].append(Button('Exit',(20,450),'small',black,100))

buttons['HELP'] = []
buttons['HELP'].append(Button('Exit',(20,450),'small',black,100))

buttons['HIGHSCORE'] = []
buttons['HIGHSCORE'].append(Button('Exit',(20,450),'small',black, 100))


def buttonMenu(menutype):
	gameDisplay=pygame.display.set_mode((display_width,display_height))
	gameDisplay.fill(l_grey)
	pygame.display.set_caption(menutype)
	Button.button_text(menutype, display_width/2, display_height/4,black,'large')
	for b in buttons[menu]:
		b.button()
	pygame.display.update()
	
def settingsMenu():
	buttonMenu('Settings')

def helpMenu():
	buttonMenu('Help')
	Button.button_text('Insert help text here',display_width/2,display_height/3,black,'small')


def highscoreMenu():
	buttonMenu('Highscore')

def MenuSelect(selection):

	global menu

	if selection == 'HELP':
		helpMenu()
	if selection == 'SETTINGS':
		settingsMenu()
	if selection == 'HIGHSCORE':
		highscoreMenu()
	if selection == 'Exit':
		menu = 'MAIN'
		for b in buttons[menu]:
			gameDisplay=pygame.display.set_mode((display_width,display_height))
			gameDisplay.fill(l_grey)
			b.button()
			pygame.display.update()
		

def menu_display():
	#THIS WHOLE PORTION IS FOR DISPLAY
	#-------------------------------------------
	global menu


	for event in pygame.event.get():
		cur = pygame.mouse.get_pos()
		#here is the code to call update
		for b in buttons[menu]:
			b.update(cur)
		if event.type == pygame.QUIT:
			pygame.quit()
			quit()

		elif event.type==pygame.MOUSEBUTTONDOWN:
			for a in buttons[menu]:
				if a.rect.collidepoint(event.pos):
					menu = a.text
					MenuSelect(menu)
				

	pygame.display.update()		

	
def main():
	gameDisplay = pygame.display.set_mode((display_width,display_height))
	pygame.display.set_caption('Minesweeper Menu')
	gameDisplay.fill(l_grey)
	pygame.display.update()
	for b in buttons[menu]:
			b.button()
	while True:
		menu_display()


main()
