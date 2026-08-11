import * as functions from "firebase-functions";
import * as admin from "firebase-admin";

const app = admin.initializeApp();
const db = app.firestore();
const colPneus = db.collection("pneus");

export const addSampleTire = functions.https.onRequest(async (request, response) => {
  const pneu = {
    largura: 225,
    altura: 50,
    aro: 17,
    marca: "Pirelli",
    modelo: "Cinturato P7",
    precoVenda: 799.99,
  };
  try {
    const docRef = await colPneus.add(pneu);
    response.send("Pne exemplo inserido. Referencia: "+docRef);
  } catch (e) {
    functions.logger.error("Erro ao inserir o pneu de exemplo.");
    response.send("Erro ao inserir o pneu de exemplo.");
  }
});
