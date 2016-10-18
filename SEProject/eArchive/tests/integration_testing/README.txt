INTRO:
	
	In order to test the integration feature of our system, we provide two files to test system.

----------------------------------------------------------------

FILES:

	1. createtable_jsonsender_test.php
	
		Change the username, password and database name in the code. This file would help you to create a new table named jsonsender_test and insert preset data into it. The test will run on this table.

	2. jsonsender_test.php

		After ran the first file to create the table used for test, you should run this file on you server. It would test whether the communication function works for you.

----------------------------------------------------------------

TEST PROCEDURE:

	1.Run createtable_jsonsender_test.php

		First, you should run the createtable_jsonsender_test.php file in your own server to create the table used for test. After running it, these sentences should be displayed:

			jsonsender_test table is created successfully!
			Insert jsonsender_test data complete! 

		It means you successfully create and insert the data used for test.
	
	2.Run jsonsender_test.php

		Second, you should run the jsonsender_test.php file in your own server. After you would see following messages displayed:

			It is the website requesting data!
			Table 1 is selected to be sent!
			[{"test_name":"Hohn","test_num":"1"},{"test_name":"Kathy","test_num":"2"},{"test_name":"Alex","test_num":"3"},{"test_name":"Jason","test_num":"4"}]

		It indicates who is asking for the data and what data is being asking (All of this option is preset in this file). Up to now, the whole test is over and it seems the communication function works successfully in you own server.