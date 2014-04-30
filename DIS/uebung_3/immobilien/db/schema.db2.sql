CREATE TABLE VSISP54.APPARTMENT (
	ID INTEGER NOT NULL,
	ESTATE_ID INTEGER NOT NULL,
	FLOOR SMALLINT,
	RENT DOUBLE,
	ROOM_COUNT SMALLINT,
	IS_BALCONY DECIMAL(1) NOT NULL,
	IS_KITCHEN DECIMAL(1) NOT NULL,
	PRIMARY KEY (ID,ESTATE_ID)
);

CREATE TABLE VSISP54.CONTRACT (
	ID INTEGER NOT NULL,
	CONTRACT_NO INTEGER,
	DATE DATE,
	PLACE VARCHAR(255),
	PRIMARY KEY (ID)
);

CREATE TABLE VSISP54.CONTRACT_PURCHASE (
	ID INTEGER NOT NULL,
	CONTRACT_ID INTEGER NOT NULL,
	SELL_ID INTEGER NOT NULL,
	INSTALLMENT_COUNT SMALLINT,
	RATE SMALLINT,
	PRIMARY KEY (ID,CONTRACT_ID,SELL_ID)
);

CREATE TABLE VSISP54.CONTRACT_TENANCY (
	ID INTEGER NOT NULL,
	CONTRACT_ID INTEGER NOT NULL,
	RENT_ID INTEGER NOT NULL,
	START_DATE DATE,
	DURATION DOUBLE,
	ADDITIONAL_COSTS DOUBLE,
	PRIMARY KEY (ID,CONTRACT_ID,RENT_ID)
);

CREATE TABLE VSISP54.ESTATE (
	ID INTEGER NOT NULL,
	CITY VARCHAR(45),
	ZIP INTEGER,
	STREET VARCHAR(255),
	STREET_NO INTEGER,
	SQUARE VARCHAR(45),
	ESTATE_AGENT_NAME VARCHAR(255) NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE VSISP54.ESTATE_AGENT (
	ID INTEGER NOT NULL,
	NAME VARCHAR(255),
	ADDRESS VARCHAR(45),
	LOGIN VARCHAR(45),
	PASSWORD VARCHAR(45),
	ESTATE_ID INTEGER NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE VSISP54.HOUSE (
	ID INTEGER NOT NULL,
	ESTATE_ID INTEGER,
	FLOOR_COUNT INTEGER,
	PRICE DOUBLE,
	IS_GARDEN INTEGER,
	PRIMARY KEY (ID)
);

CREATE TABLE VSISP54.PERSON (
	ID INTEGER NOT NULL,
	SELL_ID INTEGER NOT NULL,
	RENT_ID INTEGER NOT NULL,
	FIRST_NAME VARCHAR(255),
	NAME VARCHAR(255),
	ADDRESS VARCHAR(45),
	PRIMARY KEY (ID)
);

CREATE TABLE VSISP54.PERSON_HAS_HOUSE (
	PERSON_ID INTEGER NOT NULL,
	HOUSE_ESTATE_ID INTEGER NOT NULL,
	PRIMARY KEY (PERSON_ID,HOUSE_ESTATE_ID)
);

CREATE TABLE VSISP54.RENT (
	ID INTEGER NOT NULL,
	APPARTMENT_ID INTEGER NOT NULL,
	APPARTMENT_ESTATE_ID INTEGER NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE VSISP54.SELL (
	ID INTEGER NOT NULL,
	HOUSE_ESTATE_ID INTEGER NOT NULL,
	PRIMARY KEY (ID)
);

ALTER TABLE VSISP54.CONTRACT_PURCHASE
	ADD FOREIGN KEY (CONTRACT_ID) 
	REFERENCES CONTRACT (ID);

ALTER TABLE VSISP54.CONTRACT_PURCHASE
	ADD FOREIGN KEY (SELL_ID) 
	REFERENCES SELL (ID);



ALTER TABLE VSISP54.CONTRACT_TENANCY
	ADD FOREIGN KEY (CONTRACT_ID) 
	REFERENCES CONTRACT (ID);

ALTER TABLE VSISP54.CONTRACT_TENANCY
	ADD FOREIGN KEY (RENT_ID) 
	REFERENCES RENT (ID);



ALTER TABLE VSISP54.PERSON
	ADD FOREIGN KEY (RENT_ID) 
	REFERENCES RENT (ID);

ALTER TABLE VSISP54.PERSON
	ADD FOREIGN KEY (SELL_ID) 
	REFERENCES SELL (ID);



ALTER TABLE VSISP54.PERSON_HAS_HOUSE
	ADD FOREIGN KEY (PERSON_ID) 
	REFERENCES PERSON (ID);



ALTER TABLE VSISP54.RENT
	ADD FOREIGN KEY (APPARTMENT_ID,APPARTMENT_ESTATE_ID) 
	REFERENCES APPARTMENT (ID,ESTATE_ID);



CREATE INDEX VSISP54.SQL140416134943640 ON "VSISP54 ".APPARTMENT (ID,ESTATE_ID);

CREATE INDEX VSISP54.SQL140416135041230 ON "VSISP54 ".SELL (ID);

CREATE INDEX VSISP54.SQL140416135314840 ON "VSISP54 ".RENT (ID);

CREATE INDEX VSISP54.SQL140416135426690 ON "VSISP54 ".PERSON (ID);

CREATE INDEX VSISP54.SQL140416135454900 ON "VSISP54 ".CONTRACT (ID);

CREATE INDEX VSISP54.SQL140416135550970 ON "VSISP54 ".CONTRACT_TENANCY (ID,CONTRACT_ID,RENT_ID);

CREATE INDEX VSISP54.SQL140416135636740 ON "VSISP54 ".CONTRACT_PURCHASE (ID,CONTRACT_ID,SELL_ID);

CREATE INDEX VSISP54.SQL140416135706090 ON "VSISP54 ".PERSON_HAS_HOUSE (PERSON_ID,HOUSE_ESTATE_ID);

CREATE INDEX VSISP54.SQL140423144521860 ON "VSISP54 ".ESTATE_AGENT (ID);

CREATE INDEX VSISP54.SQL140423144601770 ON "VSISP54 ".ESTATE (ID);

CREATE INDEX VSISP54.SQL140423150917840 ON "VSISP54 ".HOUSE (ID);
