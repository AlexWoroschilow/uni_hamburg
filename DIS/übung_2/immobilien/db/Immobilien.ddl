DROP TABLE vsisp54.estate_agent;
DROP TABLE vsisp54.appartment;
DROP TABLE vsisp54.house;
DROP TABLE vsisp54.person;
DROP TABLE vsisp54.tenancy;
DROP TABLE vsisp54.purchase;
DROP TABLE vsisp54.person_has_house;
DROP TABLE vsisp54.sell;
DROP TABLE vsisp54.rent;
CREATE TABLE vsisp54.estate_agent (
  id       integer GENERATED BY DEFAULT AS IDENTITY, 
  name     varchar(255), 
  address  varchar(255), 
  login    varchar(255), 
  password varchar(255), 
  PRIMARY KEY (id));
CREATE TABLE vsisp54.appartment (
  id              integer GENERATED BY DEFAULT AS IDENTITY, 
  floor           integer, 
  zip             varchar(45), 
  city            varchar(45), 
  square          varchar(45), 
  street          varchar(45), 
  street_no       varchar(45), 
  rent            float(10), 
  room_count      integer, 
  is_balcony      smallint, 
  is_kitchen      smallint, 
  estate_agent_id integer NOT NULL, 
  PRIMARY KEY (id));
CREATE TABLE vsisp54.house (
  id              integer GENERATED BY DEFAULT AS IDENTITY, 
  floor_count     smallint, 
  price           double, 
  is_garden       smallint, 
  zip             varchar(45), 
  city            varchar(45), 
  street          varchar(45), 
  street_no       varchar(45), 
  square          varchar(45), 
  estate_agent_id integer NOT NULL, 
  PRIMARY KEY (id));
CREATE TABLE vsisp54.person (
  id         integer GENERATED BY DEFAULT AS IDENTITY, 
  name_first varchar(255), 
  name_last  varchar(255), 
  address    varchar(45), 
  PRIMARY KEY (id));
CREATE TABLE vsisp54.tenancy (
  id              integer GENERATED BY DEFAULT AS IDENTITY, 
  contract_no     integer, 
  "date"          date, 
  place           varchar(255), 
  start           date, 
  duration        integer, 
  additional_cost float(10), 
  person_id       integer NOT NULL, 
  PRIMARY KEY (id));
CREATE TABLE vsisp54.purchase (
  id                integer GENERATED BY DEFAULT AS IDENTITY, 
  contract_no       integer, 
  "date"            date, 
  place             varchar(255), 
  rate              integer, 
  installment_count integer, 
  person_id         integer NOT NULL, 
  PRIMARY KEY (id));
CREATE TABLE vsisp54.person_has_house (
  person_id       integer NOT NULL, 
  house_estate_id integer NOT NULL, 
  PRIMARY KEY (person_id, 
  house_estate_id));
CREATE TABLE vsisp54.sell (
  house_id    integer NOT NULL, 
  purchase_id integer NOT NULL, 
  PRIMARY KEY (purchase_id));
CREATE TABLE vsisp54.rent (
  appartment_id integer NOT NULL, 
  tenancy_id    integer NOT NULL, 
  PRIMARY KEY (tenancy_id));
ALTER TABLE vsisp54.purchase ADD CONSTRAINT FKpurchase799994 FOREIGN KEY (person_id) REFERENCES vsisp54.person (id);
ALTER TABLE vsisp54.tenancy ADD CONSTRAINT FKtenancy152809 FOREIGN KEY (person_id) REFERENCES vsisp54.person (id);
ALTER TABLE vsisp54.rent ADD CONSTRAINT FKrent293236 FOREIGN KEY (tenancy_id) REFERENCES vsisp54.tenancy (id);
ALTER TABLE vsisp54.sell ADD CONSTRAINT FKsell856691 FOREIGN KEY (purchase_id) REFERENCES vsisp54.purchase (id);
ALTER TABLE vsisp54.sell ADD CONSTRAINT FKsell740197 FOREIGN KEY (house_id) REFERENCES vsisp54.house (id);
ALTER TABLE vsisp54.rent ADD CONSTRAINT FKrent601566 FOREIGN KEY (appartment_id) REFERENCES vsisp54.appartment (id);
ALTER TABLE vsisp54.appartment ADD CONSTRAINT FKappartment579416 FOREIGN KEY (estate_agent_id) REFERENCES vsisp54.estate_agent (id);
ALTER TABLE vsisp54.house ADD CONSTRAINT FKhouse516474 FOREIGN KEY (estate_agent_id) REFERENCES vsisp54.estate_agent (id);
CREATE UNIQUE INDEX vsisp54.estate_agent_id 
  ON vsisp54.estate_agent (id);
CREATE INDEX vsisp54.fk_appartment_estate_agent1_idx 
  ON vsisp54.appartment (estate_agent_id);
CREATE UNIQUE INDEX vsisp54.appartment_id 
  ON vsisp54.appartment (id);
CREATE INDEX vsisp54.fk_house_estate_agent1_idx 
  ON vsisp54.house (estate_agent_id);
CREATE UNIQUE INDEX vsisp54.house_id 
  ON vsisp54.house (id);
CREATE UNIQUE INDEX vsisp54.person_id 
  ON vsisp54.person (id);
CREATE INDEX vsisp54.fk_tenancy_person1_idx 
  ON vsisp54.tenancy (person_id);
CREATE UNIQUE INDEX vsisp54.tenancy_id 
  ON vsisp54.tenancy (id);
CREATE INDEX vsisp54.fk_purchase_person1_idx 
  ON vsisp54.purchase (person_id);
CREATE UNIQUE INDEX vsisp54.purchase_id 
  ON vsisp54.purchase (id);
CREATE INDEX vsisp54.fk_person_has_house_house1_idx 
  ON vsisp54.person_has_house (house_estate_id);
CREATE INDEX vsisp54.fk_person_has_house_person1_idx 
  ON vsisp54.person_has_house (person_id);
CREATE INDEX vsisp54.fk_sell_house1_idx 
  ON vsisp54.sell (house_id);
CREATE INDEX vsisp54.fk_rent_appartment1_idx 
  ON vsisp54.rent (appartment_id);
