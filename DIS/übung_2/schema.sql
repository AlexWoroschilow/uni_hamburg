
CREATE SCHEMA IF NOT EXISTS `uebung2` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;

-- -----------------------------------------------------
-- Table `uebung2`.`estate_agent`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`estate_agent` (
  `name` VARCHAR(255) NOT NULL,
  `address` VARCHAR(45) NULL,
  `login` VARCHAR(45) NULL,
  `password` VARCHAR(45) NULL,
  `estate_id` INT NOT NULL,
  PRIMARY KEY (`name`),
  INDEX `fk_estate_agent_estate1_idx` (`estate_id` ASC),
  CONSTRAINT `fk_estate_agent_estate1`
    FOREIGN KEY (`estate_id`)
    REFERENCES `uebung2`.`estate` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`estate`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`estate` (
  `id` INT NOT NULL,
  `city` VARCHAR(45) NULL,
  `zip` INT(11) NULL,
  `street` VARCHAR(255) NULL,
  `street_no` INT UNSIGNED NULL,
  `square` VARCHAR(45) NULL,
  `estate_agent_name` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_estate_estate_agent_idx` (`estate_agent_name` ASC),
  CONSTRAINT `fk_estate_estate_agent`
    FOREIGN KEY (`estate_agent_name`)
    REFERENCES `uebung2`.`estate_agent` (`name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`appartment`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`appartment` (
  `id` INT NOT NULL,
  `estate_id` INT NOT NULL,
  `floor` SMALLINT UNSIGNED NULL,
  `rent` DOUBLE UNSIGNED NULL,
  `room_count` SMALLINT UNSIGNED NULL,
  `is_balcony` TINYINT(1) NULL,
  `is_kitchen` TINYINT(1) NULL,
  PRIMARY KEY (`id`, `estate_id`),
  INDEX `fk_appartment_estate1_idx` (`estate_id` ASC),
  CONSTRAINT `fk_appartment_estate1`
    FOREIGN KEY (`estate_id`)
    REFERENCES `uebung2`.`estate` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`house`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`house` (
  `estate_id` INT NOT NULL,
  `floor_count` SMALLINT UNSIGNED NULL,
  `price` DOUBLE UNSIGNED NULL,
  `is_garden` TINYINT(1) NULL,
  PRIMARY KEY (`estate_id`),
  CONSTRAINT `fk_house_estate1`
    FOREIGN KEY (`estate_id`)
    REFERENCES `uebung2`.`estate` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`sell`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`sell` (
  `id` INT NOT NULL,
  `house_estate_id` INT NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_sell_house1_idx` (`house_estate_id` ASC),
  CONSTRAINT `fk_sell_house1`
    FOREIGN KEY (`house_estate_id`)
    REFERENCES `uebung2`.`house` (`estate_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`rent`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`rent` (
  `id` INT NOT NULL,
  `appartment_id` INT NOT NULL,
  `appartment_estate_id` INT NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_rent_appartment1_idx` (`appartment_id` ASC, `appartment_estate_id` ASC),
  CONSTRAINT `fk_rent_appartment1`
    FOREIGN KEY (`appartment_id` , `appartment_estate_id`)
    REFERENCES `uebung2`.`appartment` (`id` , `estate_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`person`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`person` (
  `id` INT NOT NULL,
  `sell_id` INT NOT NULL,
  `rent_id` INT NOT NULL,
  `first_name` VARCHAR(255) NULL,
  `name` VARCHAR(255) NULL,
  `address` VARCHAR(45) NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_person_sell1_idx` (`sell_id` ASC),
  INDEX `fk_person_rent1_idx` (`rent_id` ASC),
  CONSTRAINT `fk_person_sell1`
    FOREIGN KEY (`sell_id`)
    REFERENCES `uebung2`.`sell` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_person_rent1`
    FOREIGN KEY (`rent_id`)
    REFERENCES `uebung2`.`rent` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`contract`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`contract` (
  `id` INT NOT NULL,
  `contract_no` INT NULL,
  `date` DATE NULL,
  `place` VARCHAR(255) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`contract_tenancy`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`contract_tenancy` (
  `id` INT NOT NULL,
  `contract_id` INT NOT NULL,
  `rent_id` INT NOT NULL,
  `start_date` DATE NULL,
  `duration` DOUBLE UNSIGNED NULL,
  `additional_costs` DOUBLE UNSIGNED NULL,
  PRIMARY KEY (`id`, `contract_id`, `rent_id`),
  INDEX `fk_contract_tenancy_contract1_idx` (`contract_id` ASC),
  INDEX `fk_contract_tenancy_rent1_idx` (`rent_id` ASC),
  CONSTRAINT `fk_contract_tenancy_contract1`
    FOREIGN KEY (`contract_id`)
    REFERENCES `uebung2`.`contract` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_contract_tenancy_rent1`
    FOREIGN KEY (`rent_id`)
    REFERENCES `uebung2`.`rent` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`contract_purchase`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`contract_purchase` (
  `id` INT NOT NULL,
  `contract_id` INT NOT NULL,
  `sell_id` INT NOT NULL,
  `installment_count` SMALLINT UNSIGNED NULL,
  `rate` SMALLINT UNSIGNED NULL,
  PRIMARY KEY (`id`, `contract_id`, `sell_id`),
  INDEX `fk_contract_purchase_contract1_idx` (`contract_id` ASC),
  INDEX `fk_contract_purchase_sell1_idx` (`sell_id` ASC),
  CONSTRAINT `fk_contract_purchase_contract1`
    FOREIGN KEY (`contract_id`)
    REFERENCES `uebung2`.`contract` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_contract_purchase_sell1`
    FOREIGN KEY (`sell_id`)
    REFERENCES `uebung2`.`sell` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `uebung2`.`person_has_house`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `uebung2`.`person_has_house` (
  `person_id` INT NOT NULL,
  `house_estate_id` INT NOT NULL,
  PRIMARY KEY (`person_id`, `house_estate_id`),
  INDEX `fk_person_has_house_house1_idx` (`house_estate_id` ASC),
  INDEX `fk_person_has_house_person1_idx` (`person_id` ASC),
  CONSTRAINT `fk_person_has_house_person1`
    FOREIGN KEY (`person_id`)
    REFERENCES `uebung2`.`person` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_person_has_house_house1`
    FOREIGN KEY (`house_estate_id`)
    REFERENCES `uebung2`.`house` (`estate_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;
