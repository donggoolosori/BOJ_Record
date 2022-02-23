'use strict';
const fs = require('fs');

class Heap {
  constructor() {
    this.heap = [];
  }

  push(x) {
    this.heap.push(x);

    let cur = this.heap.length - 1,
      par = parseInt((cur - 1) / 2);

    while (cur > 0 && this.heap[cur].cost < this.heap[par].cost) {
      const temp = this.heap[cur].cost;
      this.heap[cur].cost = this.heap[par].cost;
      this.heap[par].cost = temp;

      cur = par;
      par = parseInt((cur - 1) / 2);
    }
  }

  empty() {
    return this.heap.length === 0;
  }

  top() {
    if (this.empty()) {
      throw new Error('Bad top(). Heap is empty.');
    }
    return this.heap[0];
  }

  pop() {
    if (this.empty()) {
      throw new Error('Bad pop(). Heap is empty.');
    }

    this.heap[0] = this.heap[this.heap.length - 1];
    this.heap.pop();

    let cur = 0,
      left = cur * 2 + 1,
      right = cur * 2 + 2;

    while (left < this.heap.length) {
      let swapVal = this.heap[left].cost,
        swapIdx = left;
      if (right < this.heap.length) {
        if (swapVal > this.heap[right].cost) {
          swapVal = this.heap[right].cost;
          swapIdx = right;
        }
      }

      const temp = this.heap[cur].cost;
      this.heap[cur].cost = this.heap[swapIdx].cost;
      this.heap[swapIdx].cost = temp;

      cur = swapIdx;
      left = cur * 2 + 1;
      right = cur * 2 + 2;
    }
  }
}

function solution(input) {
  const n = Number(input[0]);
  const coordinates = input.slice(1).map((str) => str.split(' ').map(Number));

  const graph = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => 0)
  );

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const costX = Math.abs(coordinates[i][0] - coordinates[j][0]);
      const costY = Math.abs(coordinates[i][1] - coordinates[j][1]);
      const costZ = Math.abs(coordinates[i][2] - coordinates[j][2]);
      const cost = Math.min(costX, costY, costZ);

      graph[i][j] = cost;
      graph[j][i] = cost;
    }
  }

  console.log(graph);

  // prim
  function prim() {
    let ret = 0;

    const visit = Array.from({ length: n }, () => 0);

    const heap = new Heap();

    visit[0] = true;
    for (let i = 1; i < n; i++) {
      heap.push({ idx: i, cost: graph[0][i] });
    }

    while (!heap.empty()) {
      const { idx, cost } = heap.top();
      heap.pop();

      if (visit[idx]) continue;
      visit[idx] = true;
      ret += cost;
      console.log(idx, cost);

      for (let i = 0; i < n; i++) {
        if (visit[i]) continue;
        heap.push({ idx: i, cost: graph[idx][i] });
      }
    }

    return ret;
  }

  console.log(prim());
}

const input = fs.readFileSync('input.txt', 'utf-8').split('\n');
// const input = fs.readFileSync(0, 'utf-8').split('\n');

solution(input);
