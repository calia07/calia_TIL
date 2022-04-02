import React, {useState} from 'react';
import {SafeAreaView, Button} from 'react-native';
import Greeting from './components/Greeting';
import Box from './components/Box';

const App = () => {
  const [visible, setVisible] = useState(true);
  const onPress = () => {
    setVisible(!visible);
  };
  return (
    <SafeAreaView>
      <Button title="토글" onPress={onPress} />
      {visible ? <Box rounded={true} size="large" color="blue" /> : null}
    </SafeAreaView>
  );
};
export default App;
