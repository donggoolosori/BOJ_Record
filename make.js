const axios = require('axios');
const cheerio = require('cheerio');
const prompt = require('prompt');
const fs = require('fs');
const path = require('path');

const languages = ['cpp', 'js', 'py'];

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
      language: {
        description: `language(${languages}): `,
        delimiter: ' ',
      },
    },
  },
  async (err, result) => {
    if (err) {
      return;
    }
    const { problemNumber, language } = result;

    makeSolutionFile(problemNumber, language);
  }
);

function makeExampleFile(examples, $) {
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

  return { inputs, outputs };
}

async function makeSolutionFile(problemNumber, language) {
  if (!languages.includes(language)) {
    throw new Error('Invalid language input');
  }
  const { title, examples, $ } = await crawlProblem(problemNumber);

  const { inputs, outputs } = makeExampleFile(examples, $);

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

  console.log(`${problemNumber} "${title}"`);

  inputs.forEach((input, idx) =>
    fs.writeFileSync(path.join(inputDir, `input-${idx}.txt`), input)
  );
  console.log('🚀 inputs of testcase is generated!');

  outputs.forEach((output, idx) =>
    fs.writeFileSync(path.join(outputDir, `output-${idx}.txt`), output)
  );
  console.log('🚀 outputs of testcase is generated!');

  const templatePath = path.join(__dirname, `template.${language}`);
  const solutionPath = path.join(dir, `solution.${language}`);

  fs.copyFileSync(templatePath, solutionPath);

  console.log(`🚀 solution.${language} is generated!`);
}

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

  return { title, examples, $ };
}
