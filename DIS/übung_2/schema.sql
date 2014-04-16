 
SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`estate_agent`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`estate_agent` (
  `name` VARCHAR(255) NOT NULL,
  `address` VARCHAR(45) NULL,
  `login` VARCHAR(45) NULL,
  `password` VARCHAR(45) NULL,
  `estate_id` INT NOT NULL,
  PRIMARY KEY (`name`),
  INDEX `fk_estate_agent_estate1_idx` (`estate_id` ASC),
  CONSTRAINT `fk_estate_agent_estate1`
    FOREIGN KEY (`estate_id`)
    REFERENCES `mydb`.`estate` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`estate`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`estate` (
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
    REFERENCES `mydb`.`estate_agent` (`name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`appartment`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`appartment` (
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
    REFERENCES `mydb`.`estate` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`house`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`house` (
  `estate_id` INT NOT NULL,
  `floor_count` SMALLINT UNSIGNED NULL,
  `price` DOUBLE UNSIGNED NULL,
  `is_garden` TINYINT(1) NULL,
  PRIMARY KEY (`estate_id`),
  CONSTRAINT `fk_house_estate1`
    FOREIGN KEY (`estate_id`)
    REFERENCES `mydb`.`estate` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`sell`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`sell` (
  `id` INT NOT NULL,
  `house_estate_id` INT NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_sell_house1_idx` (`house_estate_id` ASC),
  CONSTRAINT `fk_sell_house1`
    FOREIGN KEY (`house_estate_id`)
    REFERENCES `mydb`.`house` (`estate_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`rent`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`rent` (
  `id` INT NOT NULL,
  `appartment_id` INT NOT NULL,
  `appartment_estate_id` INT NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_rent_appartment1_idx` (`appartment_id` ASC, `appartment_estate_id` ASC),
  CONSTRAINT `fk_rent_appartment1`
    FOREIGN KEY (`appartment_id` , `appartment_estate_id`)
    REFERENCES `mydb`.`appartment` (`id` , `estate_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`person`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`person` (
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
    REFERENCES `mydb`.`sell` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_person_rent1`
    FOREIGN KEY (`rent_id`)
    REFERENCES `mydb`.`rent` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`contract`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`contract` (
  `id` INT NOT NULL,
  `contract_no` INT NULL,
  `date` DATE NULL,
  `place` VARCHAR(255) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`contract_tenancy`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`contract_tenancy` (
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
    REFERENCES `mydb`.`contract` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_contract_tenancy_rent1`
    FOREIGN KEY (`rent_id`)
    REFERENCES `mydb`.`rent` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`contract_purchase`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`contract_purchase` (
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
    REFERENCES `mydb`.`contract` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_contract_purchase_sell1`
    FOREIGN KEY (`sell_id`)
    REFERENCES `mydb`.`sell` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`person_has_house`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`person_has_house` (
  `person_id` INT NOT NULL,
  `house_estate_id` INT NOT NULL,
  PRIMARY KEY (`person_id`, `house_estate_id`),
  INDEX `fk_person_has_house_house1_idx` (`house_estate_id` ASC),
  INDEX `fk_person_has_house_person1_idx` (`person_id` ASC),
  CONSTRAINT `fk_person_has_house_person1`
    FOREIGN KEY (`person_id`)
    REFERENCES `mydb`.`person` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_person_has_house_house1`
    FOREIGN KEY (`house_estate_id`)
    REFERENCES `mydb`.`house` (`estate_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
