package de.dis2011;

import de.dis2011.data.*;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        showMenuMain();
    }

    /**
     * Main menu
     * display menu and process actions
     * for this menu
     */
    public static void showMenuMain() {

        Menu menu = (new Menu("Main menu"))
                .addEntry("Manage agents", (item) -> {
                    EntityManager entityManager = new EntityManager();
                    String login = FormUtil.readString("Login");
                    String password = FormUtil.readString("Password");
                    if (entityManager.loginAsManager(login, password)) {
                        System.out.println("Authentication success!");
                        showMenuAgents();
                        return true;
                    }
                    System.out.println("Manager account not found.");
                    System.out.println("Pair of login and password was wrong.");
                    return true;
                }).addEntry("Manage estates", (item) -> {
                    EntityManager entityManager = new EntityManager();
                    String login = FormUtil.readString("Login");
                    String password = FormUtil.readString("Password");
                    if (entityManager.loginAsEstateAgent(login, password)) {
                        showMenuEstates();
                        return true;
                    }
                    System.out.println("Estate agent account not found.");
                    System.out.println("Pair of login and password was wrong.");
                    return true;
                }).addEntry("Manage contracts", (item) -> {
                    showMenuContracts();
                    return true;
                }).addEntry("Exit", (item) -> {
                    return false;
                });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Show menu to rule agent accounts
     * create, update or remove entities
     */
    public static void showMenuAgents() {
        Menu menu = (new Menu("Main menu >> Manage agents"))
                .addEntry("Create account", (item) -> {
                    showMenuAgentsCreate();
                    return true;
                }).addEntry("Modify account", (item) -> {
                    showMenuAgentsEdit();
                    return true;
                }).addEntry("Delete account", (item) -> {
                    showMenuAgentsEdit();
                    return true;
                }).addEntry("Previous menu", (item) -> {
                    return false;
                });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Create agents
     */
    public static void showMenuAgentsCreate() {
        EstateAgent makler = (new EstateAgent())
                .setEstate(showMenuContractCreatePurchaseChooseHouse().getEstate())
                .setName(FormUtil.readString("Name"))
                .setAddress(FormUtil.readString("Address"))
                .setLogin(FormUtil.readString("Login"))
                .setPassword(FormUtil.readString("Password"));
        (new EntityManager()).persist(makler);
        System.out.println(">> Account has been created!");
    }

    /**
     * Display list of agents
     * modify each agent by choosing list element
     */
    public static void showMenuAgentsEdit() {
        Menu menu = new Menu("Main menu >> Manage agents >> Edit agent");
        final ArrayList<EstateAgent> collection = (new EntityManager()).getEstateAgents();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                EstateAgent agent = collection.get(i);
                menu.addEntry("Edit: " + agent.getName(), (item) -> {
                    agent.setName(FormUtil.readString("Name (" + agent.getName() + ")"))
                            .setAddress(FormUtil.readString("Address (" + agent.getAddress() + ")"))
                            .setLogin(FormUtil.readString("Login (" + agent.getLogin() + ")"))
                            .setPassword(FormUtil.readString("Password"));
                    (new EntityManager()).persist(agent);
                    System.out.println("Account has been updated!");
                    return true;
                });
            }
        }
        menu.addEntry("Previous menu", (item) -> {
            return false;
        });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Display list of agents
     * remove each agent by choosing list element
     */
    public static void showMenuAgentsDelete() {
        Menu menu = new Menu("Main menu >> Manage agents >> Remove agent");
        final ArrayList<EstateAgent> collection = (new EntityManager()).getEstateAgents();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                EstateAgent agent = collection.get(i);
                menu.addEntry("Remove: " + agent.getName(), (item) -> {
                    (new EntityManager()).remove(agent);
                    System.out.println("Account has been removed!");
                    return true;
                });
            }
        }
        menu.addEntry("Previous menu", (item) -> {
            return false;
        });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Show estate menu
     * actions to create, update or remove
     */
    public static void showMenuEstates() {
        Menu menu = (new Menu("Main menu >> Manage estates >> Manage estates"))
                .addEntry("Create estate", (item) -> {
                    showMenuEstateCreate();
                    return true;
                }).addEntry("Modify estate", (item) -> {
                    showMenuEstatesUpdate();
                    return true;
                }).addEntry("Delete estate", (item) -> {
                    showMenuEstatesDelete();
                    return true;
                }).addEntry("Previous menu", (item) -> {
                    return false;
                });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Show menu to create estate
     * and process menu actions
     */
    public static void showMenuEstateCreate() {
        Menu menu = (new Menu("Main menu >> Manage estates >> Manage estates >> Create estate"))
                .addEntry("Create house", (item) -> {
                    showMenuEstateCreateHouse();
                    return true;
                }).addEntry("Create apartment", (item) -> {
                    showMenuEstateCreateApartment();
                    return true;
                }).addEntry("Previous menu", (item) -> {
                    return false;
                });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Create house action
     */
    public static void showMenuEstateCreateHouse() {
        House house = (new House())
                .setEstate(
                        (new Estate())
                                .setZip(FormUtil.readInt("Zip"))
                                .setCity(FormUtil.readString("City"))
                                .setStreet(FormUtil.readString("Street"))
                                .setStreetNo(FormUtil.readInt("Street Number"))
                )
                .setFloorCount(FormUtil.readInt("Floor count"))
                .setPrice(FormUtil.readFloat("Price"))
                .setIsGarden(FormUtil.readInt("Has garden"));
        (new EntityManager()).persist(house);
        System.out.println(">> House has been created!");
    }

    /**
     * Create apartment action
     */
    public static void showMenuEstateCreateApartment() {
        Apartment apartment = (new Apartment())
                .setEstate(
                        (new Estate())
                                .setZip(FormUtil.readInt("Zip"))
                                .setCity(FormUtil.readString("City"))
                                .setStreet(FormUtil.readString("Street"))
                                .setStreetNo(FormUtil.readInt("Street Number"))
                )
                .setFloor(FormUtil.readInt("Floor"))
                .setRoomCount(FormUtil.readInt("Room count"))
                .setRent(FormUtil.readFloat("Rent"))
                .setIsBalcony(FormUtil.readBoolean("Has balcon"))
                .setIsKitchen(FormUtil.readBoolean("Has kitchen"));
        (new EntityManager()).persist(apartment);
        System.out.println(">> Apartment has been created!");
    }

    /**
     * Create menu to update estates
     * process update action here
     */
    public static void showMenuEstatesUpdate() {
        Menu menu = new Menu("Main menu >> Manage estates >> Manage estates >> Edit estate");
        final ArrayList<House> collection1 = (new EntityManager()).getHouses();
        if (!collection1.isEmpty()) {
            for (int i = 0; i < collection1.size(); ++i) {
                House estate = collection1.get(i);
                menu.addEntry("House: \n\t" + estate, (item) -> {
                    showMenuEstatesUpdateHouse(estate);
                    return true;
                });
            }
        }
        final ArrayList<Apartment> collection2 = (new EntityManager()).getApartments();
        if (!collection2.isEmpty()) {
            for (int i = 0; i < collection2.size(); ++i) {
                Apartment estate = collection2.get(i);
                menu.addEntry("Apartment: \n\t" + estate, (item) -> {
                    showMenuEstatesUpdateApartment(estate);
                    return true;
                });
            }
        }

        menu.addEntry("Previous menu", (item) -> {
            return false;
        });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Update House object
     *
     * @param estate
     */
    public static void showMenuEstatesUpdateHouse(House estate) {
        estate.setCity(FormUtil.readString("City (" + estate.getCity() + ")"))
                .setZip(FormUtil.readInt("Zip (" + estate.getZip() + ")"))
                .setStreet(FormUtil.readString("Street (" + estate.getStreet() + ")"))
                .setStreetNo(FormUtil.readInt("Street No (" + estate.getStreetNo() + ")"))
                .setFloorCount(FormUtil.readInt("Floors (" + estate.getFloorCount() + ")"))
                .setPrice(FormUtil.readFloat("Price (" + estate.getPrice() + ")"))
                .setIsGarden(FormUtil.readInt("Has Garden (" + estate.getIsGarden() + ")"));
        (new EntityManager()).persist(estate);
        System.out.println("Estate has been updated!");
    }

    /**
     * Update apartment object
     *
     * @param estate
     */
    public static void showMenuEstatesUpdateApartment(Apartment estate) {
        estate.setCity(FormUtil.readString("City (" + estate.getCity() + ")"))
                .setZip(FormUtil.readInt("Zip (" + estate.getZip() + ")"))
                .setStreet(FormUtil.readString("Street (" + estate.getStreet() + ")"))
                .setStreetNo(FormUtil.readInt("Street No (" + estate.getStreetNo() + ")"))
                .setFloor(FormUtil.readInt("Floor (" + estate.getFloor() + ")"))
                .setRoomCount(FormUtil.readInt("Rooms (" + estate.getRoomCount() + ")"))
                .setRent(FormUtil.readFloat("Rent (" + estate.getRent() + ")"))
                .setIsBalcony(FormUtil.readBoolean("Has Balcon (" + estate.getIsBalcony() + ")"))
                .setIsKitchen(FormUtil.readBoolean("Has Kitchen (" + estate.getIsKitchen() + ")"));
        (new EntityManager()).persist(estate);
        System.out.println("Estate has been updated!");
    }


    /**
     * Show menu to remove estates
     * process remove action here
     */
    public static void showMenuEstatesDelete() {
        Menu menu = new Menu("Main menu >> Manage estates >> Manage estates >> Remove estate");
        final ArrayList<House> collection1 = (new EntityManager()).getHouses();
        if (!collection1.isEmpty()) {
            for (int i = 0; i < collection1.size(); ++i) {
                House estate = collection1.get(i);
                menu.addEntry("House: \n\t" + estate, (item) -> {
                    (new EntityManager()).remove(estate);
                    System.out.println("Estate has been removed!");
                    return true;
                });
            }
        }
        final ArrayList<Apartment> collection2 = (new EntityManager()).getApartments();
        if (!collection2.isEmpty()) {
            for (int i = 0; i < collection2.size(); ++i) {
                Apartment estate = collection2.get(i);
                menu.addEntry("Apartment: \n\t" + estate, (item) -> {
                    (new EntityManager()).remove(estate);
                    System.out.println("Estate has been removed!");
                    return true;
                });
            }
        }

        menu.addEntry("Previous menu", (item) -> {
            return false;
        });

        while ((Boolean) menu.process()) ;
    }

    public static void showMenuContracts() {
        Menu menu = (new Menu("Main menu >> Manage contract"))
                .addEntry("Create person", (item) -> {
                    showMenuContractCreatePerson();
                    return true;
                }).addEntry("Create contract", (item) -> {
                    showMenuContractCreate();
                    return true;
                }).addEntry("Show all contracts", (item) -> {
                    showMenuContractsShowAll();
                    return true;
                }).addEntry("Previous menu", (item) -> {
                    return false;
                });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Create person object
     */
    public static void showMenuContractCreatePerson() {
        Person person = (new Person())
                .setFirstName(FormUtil.readString("First name"))
                .setName(FormUtil.readString("Last name"))
                .setAddress(FormUtil.readString("Address"));
        (new EntityManager()).persist(person);
        System.out.println(">> Person has been created!");
    }

    /**
     * Create contract object
     */
    public static void showMenuContractCreate() {
        Menu menu = (new Menu("Main menu >> Manage contract >> Create contract"))
                .addEntry("Create purchase contract", (item) -> {
                    showMenuContractCreatePurchase();
                    return true;
                })
                .addEntry("Create tenancy contract", (item) -> {
                    showMenuContractCreateTenancy();
                    return true;
                }).addEntry("Previous menu", (item) -> {
                    return false;
                });

        while ((Boolean) menu.process()) ;
    }

    /**
     * Action to create purchase contract
     */
    public static void showMenuContractCreatePurchase() {
        ContractPurchase contractPurchase = (new ContractPurchase())
                .setSell(
                        (new Sell())
                                .setHouse(showMenuContractCreatePurchaseChooseHouse())
                                .setPerson(showMenuContractCreatePurchaseChoosePerson())
                )
                .setContract(
                        (new Contract())
                                .setContractNo(FormUtil.readInt("Contract No"))
                                .setDate(FormUtil.readDate("Date ('MMMM d, yyyy')"))
                                .setPlace(FormUtil.readString("Place"))
                )
                .setInstallmentCount(FormUtil.readInt("Installment count"))
                .setRate(FormUtil.readInt("Rate"));
        (new EntityManager()).persist(contractPurchase);
        System.out.println(">> Purchase contract has been created!");
    }

    /**
     * Show menu to choose house
     *
     * @return
     */
    public static House showMenuContractCreatePurchaseChooseHouse() {

        Menu menu = new Menu("Main menu >> Manage contract >> Create contract >> Choose house");
        final ArrayList<House> collection1 = (new EntityManager()).getHouses();
        if (!collection1.isEmpty()) {
            for (int i = 0; i < collection1.size(); ++i) {
                House house = collection1.get(i);
                menu.addMenuItem(new MenuItemHouse("Choose: \n\t" + house, (item) -> {
                    return house;
                }));
            }
        }

        menu.addEntry("Next step", (item) -> {
            return false;
        });

        try {
            return (House) menu.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }

    /**
     * Show menu to choose Person
     *
     * @return
     */
    public static Person showMenuContractCreatePurchaseChoosePerson() {

        Menu menu = new Menu("Main menu >> Manage contract >> Create contract >> Choose person");
        final ArrayList<Person> collection = (new EntityManager()).getPersons();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Person person = collection.get(i);
                menu.addMenuItem(new MenuItemPerson("Choose: \n\t" + person, (item) -> {
                    return person;
                }));
            }
        }

        menu.addEntry("Next step", (item) -> {
            return false;
        });

        try {
            return (Person) menu.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }


    /**
     * Create tenancy contract
     */
    public static void showMenuContractCreateTenancy() {
        ContractTenancy contractTenancy = (new ContractTenancy())
                .setRent(
                        (new Rent())
                                .setApartment(showMenuContractCreatePurchaseChooseApartment())
                                .setPerson(showMenuContractCreatePurchaseChoosePerson())
                ).setContract(
                        (new Contract())
                                .setContractNo(FormUtil.readInt("Contract No"))
                                .setDate(FormUtil.readDate("Date ('MMMM d, yyyy')"))
                                .setPlace(FormUtil.readString("Place"))
                ).setDuration(FormUtil.readFloat("Duration"))
                .setAdditionalCost(FormUtil.readFloat("Duration"))
                .setStartedAt(FormUtil.readDate("Started at ('MMMM d, yyyy')"));
        (new EntityManager()).persist(contractTenancy);
        System.out.println(">> Tenancy contract has been created!");
    }

    /**
     * Choose apartment
     *
     * @return
     */
    public static Apartment showMenuContractCreatePurchaseChooseApartment() {

        Menu menu = new Menu("Main menu >> Manage contract >> Create contract >> Choose apartment");
        final ArrayList<Apartment> collection = (new EntityManager()).getApartments();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Apartment estate = collection.get(i);
                menu.addMenuItem(new MenuItemApartment("Choose: \n\t" + estate, (item) -> {
                    return estate;
                }));
            }
        }

        menu.addEntry("Next step", (item) -> {
            return false;
        });

        try {
            return (Apartment) menu.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }

    /**
     * Show contracts
     */
    public static void showMenuContractsShowAll() {

        Menu menu = new Menu("Main menu >> Manage contract >> Show all");
        final ArrayList<ContractPurchase> collection1 = (new EntityManager()).getContractsPurchase();
        if (!collection1.isEmpty()) {
            for (int i = 0; i < collection1.size(); ++i) {
                ContractPurchase contractPurchase = collection1.get(i);

                menu.addEntry("Purchase: " + contractPurchase, (item) -> {
                    return false;
                });
            }
        }
        final ArrayList<ContractTenancy> collection2 = (new EntityManager()).getContractsTenancy();
        if (!collection2.isEmpty()) {
            for (int i = 0; i < collection2.size(); ++i) {
                ContractTenancy contractTenancy = collection2.get(i);

                menu.addEntry("Tenancy: " + contractTenancy, (item) -> {
                    return false;
                });
            }
        }
        menu.addEntry("Previous menu", (item) -> {
            return false;
        });

        while ((Boolean) menu.process()) ;
    }
}
