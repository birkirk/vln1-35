=======================================================
                     ____  ___           _        _   
                    | |  \/  |          | |      | |  
  _ __ ___  __ _  __| | .  . | ___      | |___  _| |_ 
 | '__/ _ \/ _` |/ _` | |\/| |/ _ \     | __\ \/ / __|
 | | |  __/ (_| | (_| | |  | |  __/  _  | |_ >  <| |_ 
 |_|  \___|\__,_|\__,_\_|  |_/\___| (_)  \__/_/\_\\__|

=======================================================

1) Adding a scientist:
	--> While in the main menu, enter the command "add".
	--> In the add menu, enter the command "sci".
	--> Input the information in this order:
		Name:  		_______ (Input name of a scientist)
		Gender:		_______ (Input 'F' for female or 'M' for male)
		Year of Birth:	_______ (Input year from 0 to 2016)
		Is he alive?:	_______ (Input 'Y' for yes or 'N' for no)
		Year of death:  _______ (Input year from birthyear to 2016)
		
		Notes: 	*Inputs are not case sensitive.
			*Year of death only displays if the scientist is not still alive.
	
2) Adding a computer:
	--> While in the main menu, enter the command "add".
	--> In the add menu, enter the command "comp".
	--> Input the information in this order:
		Name:		_______ (Input name of a computer)
		Type:		_______ (Input what type of computer it is)
		Was it made?:	_______ (Input 'Y' for yes or 'N' for no)
		Year made:	_______ (Input year from 0 to 2016)
		
		Notes:	*Inputs are not case sensitive.
			*Year made only displays if the computer was actually made.

3) Deleting an item:
	--> While in the main menu, enter the command "delete".
	--> In the delete menu, enter "sci" for scientists "comp" for computers.
	--> This function uses the "Search" function to find the item you want to delete.
		--> If the all parameters are left empty, the database displays all
		    items on the list. The database searches for all items that contain
         	    information you put into the search options.
		--> If more than one item contains the same substrings
		    from the search, a list of items is displayed where you have to
		    select which of them you want to delete.
	--> Confirm deletion by typing "Y" or cancel by typing "N".

		Notes:	*Inputs are not case sensitive.
			*If no items match the substrings entered in the search, nothing
			 is displayed.
			*Selecting an item to delete out of multiple items after the search
			 is done by entering the number of the item on the list, which is 
			 found on the far left of the list.
			*If an item is deleted, all connections to it are deleted as well.

4) Displaying a list of items:
	--> While in the main menu, enter the command "list".
	--> In the list menu, enter "sci" for scientists, "comp" for computers or 
	    "con" for connections between scientists and computers.
	--> To choose how the list is set up, enter the number next to the order which
	    you want the list to display the items.
	--> You can also press b to go back to the main menu.

5) Searching for items:
	--> While in the main menu, enter the command "search".
	--> In the delete menu, enter "sci" for scientists or "comp" for computers.
	--> Fill out the search inputs you need to find the item you are looking for.
	--> If the all inputs are left empty, the database displays all items on the list.
		--> The function searches for all items in the database that contain
          	    information you put into the search options and displays a list of
		    items that match you search parameters.

6) Connecting scientists and computers:
	--> While in the main menu, enter the command "connect".
	--> In the connect menu, enter "sci" to connect computers to scientists or "comp"
	    to connect scientists to computers.
i)	--> If you chose "sci", start by selecting a scientist ftom the displayed list
	    by entering the scientist's ID number.
	--> Then select one or multiple computers by entering their ID number seperated
	    by spaces and enter "Q" to connect them. "Q" can also be used to go back to the
	    main menu if no computers were selected.
ii) 	--> If you chose "comp", start by selecting a computer ftom the displayed list
	    by entering the computer's ID number.
	--> Then select one or multiple scientists by entering their ID number seperated
	    by spaces and enter "Q" to connect them. "Q" can also be used to go back to the
	    main menu if no scientists were selected.

		Notes: 	*For this function to work, there has to be at least 1 scientist 
			 and at least 1 computer in the database.
			*A message displayes to tell you if your connection was successful.
			*If a item is deleted, all connections to it are deleted as well.

7) Clear the database:
	--> While in the main menu, enter the command "connect".
	--> In the clear menu, enter "sci" to clear all scientists from the database.
	    Enter "comp" to clear all computers from the database.
	    Enter "con" to clear all connections between scientists and computers.
	    Enter "all" to clear everything from the database.
	--> Confirm by typing "Y" or cancel by typing "N".

		Notes:	*Cleared items cannot be retrieved unless you own a backup of the
			 database.

8) Laugh:
	--> While in the main menu, enter the command "joke".
	--> Enjoy a randomly generated joke.
	--> Feel good about yourself.
	--> Gain a strong self image.
	--> Become super productive.
	--> Become a god among programmers.
	--> Take over the world.
	--> Get everything you ever wanted.
	--> Become bored.
	--> Become lazy.
	--> Let others reclaim the world.
	--> Type "joke".
	--> Repeat steps 2 - 11.

9) I wonder which group made this database:
	--> Enter the hidden command "info".

------------------------------------------------------------------------------------------
		Notes:	*All commands need to be entered correctly.
------------------------------------------------------------------------------------------

