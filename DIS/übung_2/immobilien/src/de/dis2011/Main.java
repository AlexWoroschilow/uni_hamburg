package de.dis2011;

import de.dis2011.data.*;

public class Main {

    public static void main(String[] args) {
        showMenuMain();
    }

    public static void showMenuMain() {

        Menu menu = new Menu("Main menu");
        menu.addEntry("Manage agents", () -> {
            showMenuAgents();
        });
        menu.addEntry("Manage estates", () -> {
            showMenuEstates();
        });
        menu.addEntry("Manage contracts", () -> {
            showMenuContracts();
        });
        menu.addEntry("Exit", () -> {
        }, false);

        while (menu.process()) ;
    }

    public static void showMenuAgents() {
        Menu menu = new Menu("Manage agents menu");
        menu.addEntry("Create account", () -> {
            EstateAgent makler = (new EstateAgent())
                    .setName(FormUtil.readString("Name"))
                    .setAddress(FormUtil.readString("Address"))
                    .setLogin(FormUtil.readString("Login"))
                    .setPassword(FormUtil.readString("Password"));
            (new EntityManager()).persist(makler);
            System.out.println(">> Account has been created!");
        });

        menu.addEntry("Modify account", () -> {
            System.out.println(">> Account has been updated!");
        });
        menu.addEntry("Delete account", () -> {
            System.out.println(">> Account has been removed!");
        });
        menu.addEntry("Previous menu", () -> {
        }, false);

        while (menu.process()) ;
    }

    public static void showMenuEstates() {
        Menu menu = new Menu("Manage estates menu");
        menu.addEntry("Create estate", () -> {
            showMenuEstateCreate();
        });
        menu.addEntry("Modify estate", () -> {
            System.out.println(">> Estate has been updated!");
        });
        menu.addEntry("Delete estate", () -> {
            System.out.println(">> Estate has been removed!");
        });
        menu.addEntry("Previous menu", () -> {
        }, false);

        while (menu.process()) ;
    }

    public static void showMenuEstateCreate() {
        Menu menu = new Menu("Manage estate create");

        menu.addEntry("Create house", () -> {
            Estate estate = (new Estate())
                    .setZip(FormUtil.readInt("Zip"))
                    .setCity(FormUtil.readString("City"))
                    .setStreet(FormUtil.readString("Street"))
                    .setStreetNo(FormUtil.readInt("Street Number"));
            (new EntityManager()).persist(estate);
            House house = (new House())
                    .setEstate(estate)
                    .setFloorCount(FormUtil.readInt("Floor count"))
                    .setPrice(FormUtil.readFloat("Price"))
                    .setIsGarden(FormUtil.readBoolean("Has garden"));
            (new EntityManager()).persist(house);
            System.out.println(">> House has been created!");
        });

        menu.addEntry("Create apartment", () -> {
            Estate estate = (new Estate())
                    .setZip(FormUtil.readInt("Zip"))
                    .setCity(FormUtil.readString("City"))
                    .setStreet(FormUtil.readString("Street"))
                    .setStreetNo(FormUtil.readInt("Street Number"));
            (new EntityManager()).persist(estate);
            Apartment apartment = (new Apartment())
                    .setEstate(estate)
                    .setFloor(FormUtil.readInt("Floor"))
                    .setRoomCount(FormUtil.readInt("Room count"))
                    .setRent(FormUtil.readFloat("Rent"))
                    .setIsBalcony(FormUtil.readBoolean("Has balcon"))
                    .setIsKitchen(FormUtil.readBoolean("Has kitchen"));
            (new EntityManager()).persist(apartment);
            System.out.println(">> Apartment has been created!");
        });

        menu.addEntry("Previous menu", () -> {
        }, false);

        while (menu.process()) ;
    }

    public static void showMenuContracts() {
        Menu menu = new Menu("Manage contracts menu");

        menu.addEntry("Create person", () -> {
            Person person = (new Person())
                    .setFirstName(FormUtil.readString("First name"))
                    .setName(FormUtil.readString("Last name"))
                    .setAddress(FormUtil.readString("Address"));
            (new EntityManager()).persist(person);
            System.out.println(">> Person has been created!");
        });

        menu.addEntry("Create contract", () -> {
            showMenuContractCreate();
        });

        menu.addEntry("Show all contracts", () -> {
            System.err.println("Manage contracts show all contracts");
        });

        menu.addEntry("Previous menu", () -> {
        }, false);

        while (menu.process()) ;
    }

    public static void showMenuContractCreate() {
        Menu menu = new Menu("Manage contract create menu");

        menu.addEntry("Create purchase contract", () -> {
            ContractPurchase contractPurchase = (new ContractPurchase());
            (new EntityManager()).persist(contractPurchase);
            System.out.println(">> Purchase contract has been created!");
        });

        menu.addEntry("Create tenancy contract", () -> {
            ContractTenancy contractTenancy = (new ContractTenancy());
            (new EntityManager()).persist(contractTenancy);
            System.out.println(">> Tenancy contract has been created!");
        });

        menu.addEntry("Previous menu", () -> {
        }, false);

        while (menu.process()) ;
    }

}
