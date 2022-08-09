const axios = require('axios');
const cheerio = require('cheerio');
const prompt = require('prompt');
const fs = require('fs');
const path = require('path');

prompt.message = '';
prompt.delimiter = '';

prompt.start();

prompt.get(
  {
    properties: {
      problemNumber: {
        description: 'problem number: ',
        delimiter: ' ',
      },
    },
  },
  async (err, result) => {
    if (err) {
      return;
    }
    const { problemNumber } = result;

    crawlProblem(problemNumber);
  }
);

async function getHtml(problemNumber) {
  const { data } = await axios.get(
    `https://www.acmicpc.net/problem/${problemNumber}`
  );
  return data;
}

async function crawlProblem(problemNumber) {
  const html = await getHtml(problemNumber);
  const $ = cheerio.load(html);
  const title = $('span#problem_title').text().trim();

  const examples = $('pre.sampledata');

  const inputs = examples
    .filter(function () {
      return $(this)
        .attr()
        ?.id.match(/sample-input-\d+/);
    })
    .map(function () {
      return $(this).text();
    })
    .get();

  const outputs = examples
    .filter(function () {
      return $(this)
        .attr()
        ?.id.match(/sample-output-\d+/);
    })
    .map(function () {
      return $(this).text();
    })
    .get();

  const dir = path.join(__dirname, `${problemNumber}-${title}`);

  if (!fs.existsSync(dir)) {
    fs.mkdirSync(dir);
  }
  const inputDir = path.join(dir, 'input');
  const outputDir = path.join(dir, 'output');
  if (!fs.existsSync(inputDir)) {
    fs.mkdirSync(inputDir);
  }
  if (!fs.existsSync(outputDir)) {
    fs.mkdirSync(outputDir);
  }

  let solutionNum = 0;

  console.log(`${problemNumber} "${title}"`);
  inputs.forEach((input, idx) =>
    fs.writeFileSync(path.join(inputDir, `input-${idx}.txt`), input)
  );
  console.log('🚀 inputs of testcase is generated!');
  outputs.forEach((output, idx) =>
    fs.writeFileSync(path.join(outputDir, `output-${idx}.txt`), output)
  );
  console.log('🚀 outputs of testcase is generated!');
  const jsTemplateDir = path.join(__dirname, 'template.js');
  while (true) {
    const p = path.join(dir, `solution-${solutionNum++}.js`);
    if (!fs.existsSync(p)) {
      fs.copyFileSync(jsTemplateDir, p);
      console.log(`🚀 solution-${solutionNum - 1}.js is generated!`);
      break;
    }
  }
  //TODO: jest 파일 생성
}
