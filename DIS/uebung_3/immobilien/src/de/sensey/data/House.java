package de.sensey.data;

public class House {
    private int id;
    private String zip;
    private String city;
    private String street;
    private String street_no;
    private String square;
    private int floor_count;
    private float price;
    private int is_garden;
    private Agent agent;
    private Purchase contract;

    public Purchase getContract() {
        return contract;
    }

    public House setContract(Purchase contract) {
        this.contract = contract;
        return this;
    }

    public Agent getAgent() {
        return agent;
    }

    public House setAgent(Agent agent) {
        this.agent = agent;
        return this;
    }

    /**
     * @return
     */
    public int getId() {
        return id;
    }

    /**
     * @param id
     * @return
     */
    public House setId(int id) {
        this.id = id;
        return this;
    }

    /**
     * @return
     */
    public int getFloor_count() {
        return this.floor_count;
    }

    /**
     * @param floorCount
     * @return
     */
    public House setFloor_count(int floorCount) {
        this.floor_count = floorCount;
        return this;
    }


    /**
     * @return
     */
    public float getPrice() {
        return this.price;
    }

    /**
     * @param price
     * @return
     */
    public House setPrice(float price) {
        this.price = price;
        return this;
    }

    /**
     * @return
     */
    public int getIs_garden() {
        return this.is_garden;
    }

    /**
     * @param isGarden
     * @return
     */
    public House setIs_garden(int isGarden) {
        this.is_garden = isGarden;
        return this;
    }


    /**
     * @return
     */
    public String getZip() {
        return this.zip;
    }

    /**
     * @param zip
     * @return
     */
    public House setZip(String zip) {
        this.zip = zip;
        return this;
    }

    /**
     * @return
     */
    public String getCity() {
        return this.city;
    }

    /**
     * @param city
     * @return
     */
    public House setCity(String city) {
        this.city = city;
        return this;
    }

    /**
     * @return
     */
    public String getStreet() {
        return this.street;
    }

    /**
     * @param street
     * @return
     */
    public House setStreet(String street) {
        this.street = street;
        return this;
    }

    /**
     * @return
     */
    public String getStreet_no() {
        return this.street_no;
    }

    /**
     * @return
     */
    public String getSquare() {
        return square;
    }

    /**
     * @param square
     */
    public House setSquare(String square) {
        this.square = square;
        return this;
    }

    /**
     * @param streetNo
     * @return
     */
    public House setStreet_no(String streetNo) {
        this.street_no = streetNo;
        return this;
    }

    public String toString() {
        return new String(
                "\t\t Zip: " +
                        this.getZip() +
                        "\n\t\t\t City: " +
                        this.getCity() +
                        "\n\t\t\t Street: " +
                        this.getStreet() +
                        "\n\t\t\t Street No: " +
                        this.getStreet_no() +
                        "\n\t\t\t Price: " +
                        this.getPrice() +
                        "\n\t\t\t Has garden: " +
                        this.getIs_garden() +
                        "\n\t\t\t Floor count: " +
                        this.getFloor_count()
        );
    }

}
