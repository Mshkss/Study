import axios from "axios";

const url = "http://164.215.68.12/api/courses";
async function getCourses() {
  try {
    const response = await axios.get(url);
    console.log("Курсы:", response.data);
  } catch (error) {
    console.error("Ошибка при получении курсов:", error);
  }
}

getCourses();
