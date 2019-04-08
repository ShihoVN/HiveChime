						***How to run program as of April 07, 2019***

In the main.cpp file copy then run the following code depending on what you want to check:
	
	1) Generate 20 UDP messages in the Terminal Window with a HiveId of 0002 and a HiveSize of 500 (Number of Bees)
		    BeeGeneration* BG = new BeeGeneration("0002", 500);
    				for(int i = 0; i < 20; i++){
    				cout << BG->makeBee() << endl;}


	2) Generate one UDP message
		    BeeGeneration* BG = new BeeGeneration("0002", 500);
			cout << BG->makeBee() << endl;


	3) Read in UDP messages and convert them to a vector of structs containing entry exit information and datetimes 
			   	DataContainer container;
    				DataDecoder d(&container);
    				BeeGeneration* BG = new BeeGeneration("0002", 500);

   				for(int i = 0; i < 100; i++){
    				d.decode(BG->makeBee());


    				for (int jj= 0; j < container.getUdpMessages().size(); ++j) {

        				cout << "Hive ID: " << container.getUdpMessages().at(j)->hiveId << endl;
        				cout << "Date: " << container.getUdpMessages().at(j)->date << endl ;
        				cout << "Time: " << container.getUdpMessages().at(j)->time  << endl;
        				cout << "Board: " << container.getUdpMessages().at(j)->board  << endl;
        				cout << "Gate: " << container.getUdpMessages().at(j)->gate  << endl;
        				cout << "Type: " << container.getUdpMessages().at(j)->type << endl ;
        				cout << "\n" << endl;

  					cout << "Size of array in container: " << container.getUdpMessages().size() << endl;

   				}
   			}
