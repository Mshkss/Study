import express from "express";
import { MongoClient, ObjectId } from "mongodb";
import bodyParser from "body-parser";
import path from "path";
import { fileURLToPath } from "url";

const app = express();
const PORT = 3000;
const uri = "mongodb://localhost:27017";
const dbName = "bulletinBoard";

const client = new MongoClient(uri);

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

app.use(bodyParser.urlencoded({ extended: true }));
app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

async function main() {
  await client.connect();
  console.log("Connected to MongoDB");

  const db = client.db(dbName);
  const adsCollection = db.collection("ads");

  app.get("/", async (req, res) => {
    const search = req.query.search || "";
    const query = search ? { text: { $regex: search, $options: "i" } } : {};
    const ads = await adsCollection.find(query).toArray();
    res.render("index", { ads, search });
  });

  app.post("/add", async (req, res) => {
    const text = req.body.text?.trim();
    if (text) {
      await adsCollection.insertOne({ text });
    }
    res.redirect("/");
  });

  app.post("/delete/:id", async (req, res) => {
    const id = req.params.id;
    if (ObjectId.isValid(id)) {
      await adsCollection.deleteOne({ _id: new ObjectId(id) });
    }
    res.redirect("/");
  });

  app.listen(PORT, () => {
    console.log(`Server is running at http://localhost:${PORT}`);
  });
}

main().catch(console.error);
